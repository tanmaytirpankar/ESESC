/* 
   ESESC: Super ESCalar simulator
   Copyright (C) 2003 University of Illinois.

   Contributed by Jose Renau
   Basilio Fraguela
   Smruti Sarangi
   Luis Ceze
   Milos Prvulovic

   This file is part of ESESC.

   ESESC is free software; you can redistribute it and/or modify it under the terms
   of the GNU General Public License as published by the Free Software Foundation;
   either version 2, or (at your option) any later version.

   ESESC is    distributed in the  hope that  it will  be  useful, but  WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
   PARTICULAR PURPOSE.  See the GNU General Public License for more details.

   You should  have received a copy of  the GNU General  Public License along with
   ESESC; see the file COPYING.  If not, write to the  Free Software Foundation, 59
   Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "GStats.h"
#include "Report.h"
#include "SescConf.h"
#include "gnuplot.h"
#include "bitmap.h"

/*********************** GStats */

GStats::Container *GStats::store=0;

GStats::GStats()
  :name(NULL)
{
  if (store==0)
    store = new Container;
}

GStats::~GStats() 
{
  unsubscribe();
  free(name);
}

char *GStats::getText(const char *format, va_list ap)
{
  char strid[1024];

  vsprintf(strid, format, ap);

  return strdup(strid);
}

void GStats::subscribe() 
{

  I(strcmp(getName(),"")!=0);

  if((*store).find(getName()) != (*store).end()) {
    MSG("ERROR: gstats is added twice with name [%s]. Use another name",getName());
    I(0);
  }

  (*store)[getName()] = this;
}

void GStats::unsubscribe() 
{
  I(name);

  ContainerIter it = (*store).find(name);
  if( it != (*store).end()) {
    (*store).erase(it);
  }
}

void GStats::report(const char *str)
{
  Report::field("#BEGIN GStats::report %s", str);

  for(ContainerIter it = (*store).begin(); it != (*store).end(); it++) {
    it->second->reportValue();
  }

  Report::field("#END GStats::report %s", str);
}

void GStats::reportBin()
{
  for(ContainerIter it = (*store).begin(); it != (*store).end(); it++) {
    it->second->reportBinValue();
  }
}

void GStats::reportSchema()
{
  for(ContainerIter it = (*store).begin(); it != (*store).end(); it++) {
    it->second->reportScheme();
  }
}

void GStats::flushValue()
{
  
}

void GStats::flush()
{
  for(ContainerIter it = (*store).begin(); it != (*store).end(); it++) {
    it->second->flushValue();
  }
}

GStats *GStats::getRef(const char *str) {

  ContainerIter it = (*store).find(str);
  if( it != (*store).end())
    return it->second;

  return 0;
}



/*********************** GStatsCntr */

GStatsCntr::GStatsCntr(const char *format,...)
{
  I(format!=0);      // Mandatory to pass a description
  I(format[0] != 0); // Empty string not valid

  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  data    = 0;

  name = str;
  I(*name!=0);
  subscribe();
}

double GStatsCntr::getDouble() const
{
  return data;
}

void GStatsCntr::reportValue() const
{
  Report::field("%s=%f", name, data);
}

void GStatsCntr::reportBinValue() const
{
  Report::binField(data);
}

void GStatsCntr::reportScheme() const
{
  Report::scheme(name, "8");
}

int64_t GStatsCntr::getSamples() const 
{ 
  return (int64_t)data;
}

void GStatsCntr::flushValue()
{
  data = 0;
}


/*********************** GStatsAvg */

GStatsAvg::GStatsAvg(const char *format,...)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  data  = 0;
  nData = 0;

  name = str;
  subscribe();
}

double GStatsAvg::getDouble() const
{
  return ((double)data)/nData;
}

void GStatsAvg::sample(const double v, bool en) {
  data  += en ? v : 0;
  nData += en ? 1 : 0;
}

void GStatsAvg::reportValue() const
{
  Report::field("%s:n=%lld::v=%f", name, nData, getDouble()); // n first for power
}

void GStatsAvg::reportBinValue() const
{
  Report::binField((double)nData, getDouble());
}

void GStatsAvg::reportScheme() const
{
  Report::scheme(name, "{\"n\":8,\"v\":8}");
}

int64_t GStatsAvg::getSamples() const 
{
  return nData;
}

void GStatsAvg::flushValue()
{
  data = 0;
  nData = 0;
}

/*********************** GStatsMax */

GStatsMax::GStatsMax(const char *format,...)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  maxValue = 0;
  nData    = 0;

  name     = str;

  subscribe();
}

void GStatsMax::reportValue() const
{
  Report::field("%s:max=%f:n=%lld", name, maxValue, nData);
}

void GStatsMax::reportBinValue() const
{
  Report::binField((double)nData, maxValue);
}

void GStatsMax::reportScheme() const
{
  Report::scheme(name, "{\"n\":8,\"v\":8}");
}

void GStatsMax::sample(const double v, bool en) 
{
  if (!en)
    return;
  maxValue = v > maxValue ? v : maxValue;
  nData++;
}

int64_t GStatsMax::getSamples() const 
{
  return nData;
}

void GStatsMax::flushValue()
{
  maxValue = 0;
  nData = 0;
}

/*********************** GStatsHist */

GStatsHist::GStatsHist(const char *format,...) : numSample(0), cumulative(0)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  numSample  = 0;
  cumulative = 0;

  name = str;
  subscribe();
  xlabel[0] = ylabel[0] = '\0';
  pfname[0] = '\0';
  doPlot = false;
}

void GStatsHist::reportValue() const
{
  I(H.empty()); // call stop before
    
  uint32_t maxKey = 0;

  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    Report::field("%s(%lu)=%f",name,it->first,it->second);
    if(it->first > maxKey)
      maxKey = it->first;
  }
  long double div = cumulative; // cummulative has 64bits (double has 54bits mantisa)
  div /= numSample;

  Report::field("%s:max=%lu", name, maxKey);
  Report::field("%s:v=%f"   , name, (double)div);
  Report::field("%s:n=%f"   , name, numSample);

  // gnuplot
  if(doPlot) {
    GNUPlot gp;
    if(gp.isOpen()) {
      FILE *outFile = fopen("gstats.tmp", "w");
      if(outFile) {
        for(Histogram::const_iterator it=H.begin(); it!=H.end(); it++) {
          fprintf(outFile, "%u\t%f\n", it->first, it->second);
        }
        fclose(outFile);
        if(numSample) {
          gp("set term png font \'arial\'");
          gp("set output \"%s_%s.png\"", getName(), pfname);
          gp("set style fill solid 1.0");
          gp("set xlabel \'%s\'", xlabel);
          gp("set ylabel \'%s\'", ylabel);
          gp("plot \'gstats.tmp\' using 1:2 smooth freq with boxes lc rgb\'blue\' title \'v=%f; n=%d\'", (double)div, (long)numSample);
        }
      }
    }
  }
}

void GStatsHist::reportBinValue() const
{
  I(H.empty()); // call stop before
    
  uint32_t maxKey = 0;

  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    Report::binField(it->second);
    if(it->first > maxKey)
      maxKey = it->first;
  }
  long double div = cumulative; // cummulative has 64bits (double has 54bits mantisa)
  div /= numSample;

  Report::binField((double)maxKey, (double)div, numSample);
}

void GStatsHist::reportScheme() const
{
  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    char nm[100];
    sprintf(nm, "%s(%u)", name, it->first);
    Report::scheme(nm, "8");
  }
  Report::scheme(name, "{\"max\":8,\"v\":8,\"n\":8}");
}

void GStatsHist::sample(bool enable, uint32_t key, double weight)
{
  if(enable) {
    if(H.find(key)==H.end())
      H[key]=0;

    H[key]+=weight;

    numSample += weight;
    cumulative += weight * key;
  }
}

int64_t GStatsHist::getSamples() const 
{
  return static_cast<int64_t>(numSample);
}

void GStatsHist::flushValue()
{
  H.clear();

  numSample  = 0;
  cumulative = 0;
}


/*********************** GStatsHeat */

GStatsHeat::GStatsHeat(const char *format,...) : numSample(0), cumulative(0)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  numSample  = 0;
  cumulative = 0;

  name = str;
  subscribe();
  xlabel[0] = ylabel[0] = '\0';
  pfname[0] = '\0';
  doPlot = false;
}

void GStatsHeat::reportValue() const
{
  I(H.empty()); // call stop before
    
  uint32_t maxKey = 0;
  double minValue, maxValue, extValue;
  bool extFound = false;

  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    Report::field("%s(%lu)=%f",name,it->first,it->second);
    if(it->first > maxKey) {
      maxKey = it->first;
    }
    if(extFound || minValue > it->second) {
        minValue = it->second;
    }
    if(extFound || maxValue < it->second) {
        maxValue = it->second;
    }
  }
  extValue = maxValue - minValue;
  long double div = cumulative; // cummulative has 64bits (double has 54bits mantisa)
  div /= numSample;

  Report::field("%s:max=%lu", name, maxKey);
  Report::field("%s:v=%f"   , name, (double)div);
  Report::field("%s:n=%f"   , name, numSample);

  // gnuplot
  FILE *outFile = fopen("bitmap.tmp", "w");
  if(doPlot && outFile) {
      rgb_t c = gray_colormap[0];
      rgb_t b = jet_colormap[400];
      double z;
      unsigned long x, y, i;
      unsigned long x_dim, y_dim;
      x_dim = (*computeDimX)();
      y_dim = (*computeDimY)();
      bitmap_image image(x_dim, y_dim);
      for(x = 0; x < x_dim; ++x) {
          for(y = 0; y < y_dim; ++y) {
              if(!(*isBorder)(x, y)) {
                  image.set_pixel(x, y, c.red, c.green, c.blue);
              }
              else {
                  image.set_pixel(x, y, b.red, b.green, b.blue);
              }
          }
      }
      for(Histogram::const_iterator it=H.begin(); it!=H.end(); it++) {
          x = (*computeX)(it->first);
          y = (*computeY)(it->first);
          z = 100.0 + 900.0*((extValue == 0.0)? 0.0: ((it->second - minValue)/extValue));
          i = (unsigned long) z;
          c = gray_colormap[i];
          fprintf(outFile, "x:%lu, y:%lu, i:%lu\n", x, y, i);
          image.set_pixel(x, y, c.red, c.green, c.blue);
      }
      char str[256];
      sprintf(str, "%s_%s.bmp", getName(), pfname);
      image.save_image(str);
      fclose(outFile);
  }
}

void GStatsHeat::reportBinValue() const
{
  I(H.empty()); // call stop before
    
  uint32_t maxKey = 0;

  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    Report::binField(it->second);
    if(it->first > maxKey)
      maxKey = it->first;
  }
  long double div = cumulative; // cummulative has 64bits (double has 54bits mantisa)
  div /= numSample;

  Report::binField((double)maxKey, (double)div, numSample);
}

void GStatsHeat::reportScheme() const
{
  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    char nm[100];
    sprintf(nm, "%s(%u)", name, it->first);
    Report::scheme(nm, "8");
  }
  Report::scheme(name, "{\"max\":8,\"v\":8,\"n\":8}");
}

void GStatsHeat::sample(bool enable, uint32_t key, double weight)
{
  if(enable) {
    if(H.find(key)==H.end())
      H[key]=0;

    H[key]+=weight;

    numSample += weight;
    cumulative += weight * key;
  }
}

int64_t GStatsHeat::getSamples() const 
{
  return static_cast<int64_t>(numSample);
}

void GStatsHeat::flushValue()
{
  H.clear();

  numSample  = 0;
  cumulative = 0;
}


/*********************** GStatsSack */

GStatsSack::GStatsSack(const char *format,...)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  name = str;
  subscribe();
  xlabel[0] = ylabel[0] = '\0';
  pfname[0] = '\0';
  doPlot = false;
}

void GStatsSack::reportValue() const
{
  if(data.size() == 0) {
    return;
  }

  Frequency F;
  for(unsigned long i = 0; i < data.size(); ++i) {
    long key = data[i];
    if(F.find(key) == F.end()) {
      F[key]=0;
    }
    F[key]+=1;
  }

  FILE *outFile = fopen("gstats.tmp", "w");
  long num = 0;
  double div = 0.0;
  for(Frequency::const_iterator it=F.begin(); it!=F.end(); it++) {
    Report::field("%s(%lu)=%f", name, it->first, it->second);
    if(outFile) {
      fprintf(outFile, "%u\t%f\n", it->first, it->second);
    }
    div += (double)it->first * it->second;
    num++;
  }
  div /= (double) num;
  Report::field("%s:val=%lg", name, div);
  Report::field("%s:num=%ld", name, num);

  // gnuplot
  if(outFile) {
    fclose(outFile);
    if(doPlot && (num > 0)) {
      GNUPlot gp;
      if(gp.isOpen()) {
        gp("set term png font \'arial\'");
        gp("set output \"%s_%s.png\"", getName(), pfname);
        //gp("set style fill solid 1.0");
        gp("set xlabel \'%s\'", xlabel);
        gp("set ylabel \'%s\'", ylabel);
        gp("plot \'gstats.tmp\' using 1:2 smooth freq with boxes lc rgb\'violet\' title \'v=%f; n=%d\'", (double)div, (long)num);
        //gp("plot \'gstats.tmp\' using 1:2 with lines lc rgb\'violet\' title \'v=%f; n=%d\'", (double)div, (long)num);
      }
    }
  }
  F.clear();
}

void GStatsSack::reportBinValue() const
{
  printf("ERROR: 'GStatsSack::reportBinValue()' has not yet been implemeted!\n");
}

void GStatsSack::reportScheme() const
{
  printf("ERROR: 'GStatsSack::reportScheme()' has not yet been implemeted!\n");
}

int64_t GStatsSack::getSamples() const 
{
  printf("ERROR: 'GStatsSack::getSamples()' has not yet been implemeted!\n");
  return 0;
}

void GStatsSack::flushValue()
{
  data.clear();
}


/*********************** GStatsFreq */

GStatsFreq::GStatsFreq(const char *format,...) : numSample(0), cumulative(0)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  numSample  = 0;
  cumulative = 0;
  bucketSize = 0;

  name = str;
  subscribe();
  xlabel[0] = ylabel[0] = '\0';
  pfname[0] = '\0';
  doPlot = false;
  doBucket = false;
}

void GStatsFreq::reportValue() const
{
  I(H.empty()); // call stop before

  Frequency F, S, D, N;
  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    uint32_t key = (uint32_t)it->second;
    if(F.find(key)==F.end())
      F[key]=0;
    F[key]+=1;
  }

  if(doBucket) {
    for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
      double key = it->second;
      uint32_t idx = it->first / bucketSize;
      if(N.find(idx)==N.end()){
        N[idx]=0;
        S[idx]=0;
      }
      N[idx]+=1;
      S[idx]+=key;
    }
    for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
      uint32_t idx = it->first / bucketSize;
      double avg = S[idx]/N[idx];
      double dev = (avg - it->second)*(avg - it->second);
      if(D.find(idx)==D.end()) {
        D[idx]=0;
      }
      D[idx]+=dev;
    }
    S.clear();
    for(Frequency::const_iterator it=D.begin();it!=D.end();it++) {
      uint32_t idx = it->first;
      double sdv = sqrt(D[idx]/N[idx]);
      uint32_t bin = (uint32_t) sdv;
      if(S.find(bin)==S.end()) {
        S[bin]=0;
      }
      S[bin]+=1;
    }
    N.clear();
    D.clear();
    for(Frequency::const_iterator it=S.begin(); it!=S.end(); it++) {
      Report::field("%s-SDF(%lu)=%f", name, it->first, it->second);
    }
  }
  

  FILE *outFile = fopen("gstats.tmp", "w");
  long num = 0;
  double div = 0.0;
  for(Frequency::const_iterator it=F.begin(); it!=F.end(); it++) {
    Report::field("%s(%lu)=%f", name, it->first, it->second);
    if(outFile) {
      fprintf(outFile, "%u\t%f\n", it->first, it->second);
    }
    div += (double)it->first * it->second;
    num++;
  }
  div /= (double) num;
  Report::field("%s:val=%lg", name, div);
  Report::field("%s:num=%ld", name, num);

  // gnuplot
  if(outFile) {
    fclose(outFile);
    if(doPlot && (num > 0)) {
      GNUPlot gp;
      if(gp.isOpen()) {
        gp("set term png font \'arial\'");
        gp("set output \"%s_%s.png\"", getName(), pfname);
        //gp("set style fill solid 1.0");
        gp("set xlabel \'%s\'", xlabel);
        gp("set ylabel \'%s\'", ylabel);
        //gp("plot \'gstats.tmp\' using 1:2 smooth freq with boxes lc rgb\'red\' title \'v=%f; n=%d\'", (double)div, (long)num);
        gp("plot \'gstats.tmp\' using 1:2 with lines lc rgb\'red\' title \'v=%f; n=%d\'", (double)div, (long)num);
      }
    }
  }
  F.clear();
}

void GStatsFreq::reportBinValue() const
{
  I(H.empty()); // call stop before
    
  uint32_t maxKey = 0;

  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    Report::binField(it->second);
    if(it->first > maxKey)
      maxKey = it->first;
  }
  long double div = cumulative; // cummulative has 64bits (double has 54bits mantisa)
  div /= numSample;

  Report::binField((double)maxKey, (double)div, numSample);
}

void GStatsFreq::reportScheme() const
{
  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
    char nm[100];
    sprintf(nm, "%s(%u)", name, it->first);
    Report::scheme(nm, "8");
  }
  Report::scheme(name, "{\"max\":8,\"v\":8,\"n\":8}");
}

void GStatsFreq::sample(bool enable, uint32_t key, double weight)
{
  if(enable) {
    if(H.find(key)==H.end())
      H[key]=0;

    H[key]+=weight;

    numSample += weight;
    cumulative += weight * key;
  }
  else {
    if(H.find(key)==H.end()) {
      H[key]=weight;
    }
    else {
      H[key]=0;
    }

    numSample += weight;
    cumulative += weight * key;
  }
}

int64_t GStatsFreq::getSamples() const 
{
  return H.size();
}

void GStatsFreq::flushValue()
{
  H.clear();

  numSample  = 0;
  cumulative = 0;
}

/*********************** GStatsTrac */

GStatsTrac::GStatsTrac(const char *format,...)
  : numSample(0)
  , lastSample(0)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  //numSample  = 0;
  //lastSample = 0;

  name = str;
  subscribe();
  xlabel[0] = ylabel[0] = '\0';
  pfname[0] = '\0';
  doPlot = false;
}

void GStatsTrac::reportValue() const
{
  I(H.empty()); // call stop before

  FILE *outFile = fopen("gstats.tmp", "w");
  for(uint32_t i = 0; i < numSample; ++i) {
    Report::field("%s(%lu)=%f", name, Index[i], Value[i]);
    if(outFile) {
      fprintf(outFile, "%u\t%g\n", Index[i], Value[i]);
    }
  }

  Report::field("%s:max=%f", name, maxSample);
  Report::field("%s:val=%f", name, lastSample);
  Report::field("%s:num=%f", name, numSample);

  // make gnu plot
  if(outFile != NULL) {
    fclose(outFile);

    if(doPlot && (numSample > 0)) {
      GNUPlot gp;
      if(gp.isOpen()) {
        gp("set term png font \'arial\'");
        gp("set output \"%s_%s.png\"", getName(), pfname);
        //gp("set style fill solid 0.5");
        gp("set ylabel \'%s\'", ylabel);
        gp("set xlabel \'%s\'", xlabel);
        gp("plot \'gstats.tmp\' using 1:2 with lines lc rgb\'blue\' title \'v=%f; m=%f; n=%d\'", (double)lastSample, (double)maxSample, (long)numSample);
      }
    }
  }
}

void GStatsTrac::reportBinValue() const
{
  I(H.empty()); // call stop before

  for(uint32_t i = 0; i < numSample; ++i) {
    Report::binField(Value[i]);
  }

  Report::binField((double)maxSample, (double)lastSample, numSample);
}

void GStatsTrac::reportScheme() const
{
  for(uint32_t i = 0; i < numSample; ++i) {
    char nm[100];
    sprintf(nm, "%s(%u)", name, Index[i]);
    Report::scheme(nm, "8");
  }
  Report::scheme(name, "{\"max\":8,\"v\":8,\"n\":8}");
}

void GStatsTrac::sample(bool enable, uint32_t key, double val)
{
  if(enable) {
    Index.push_back(key);
    Value.push_back(val);
    lastSample = val;
    if(numSample > 0) {
      maxSample = (lastSample > maxSample)? lastSample: maxSample;
    }
    else {
      maxSample = lastSample;
    }
    numSample++;
  }
}

int64_t GStatsTrac::getSamples() const 
{
  return static_cast<int64_t>(numSample);
}

void GStatsTrac::flushValue()
{
  Index.clear();
  Value.clear();

  numSample  = 0;
  lastSample = 0;
  maxSample = 0;
}

/*********************** GStatsPie */

GStatsPie::GStatsPie(const char *format,...)
{
  char *str;
  va_list ap;

  va_start(ap, format);
  str = getText(format, ap);
  va_end(ap);

  name = str;
  subscribe();

  label[0] = '\0';
  pfname[0] = '\0';
}

void GStatsPie::reportValue() const
{
  // gnuplot
  GNUPlot gp;
  if(gp.isOpen()) {
    gp("set term png font \'arial\'");
    gp("set output \"%s_%s.png\"", getName(), pfname);
    //gp("set size square");
    double x = 0.27;
    double y = 0.5;
    double d = 0.25;
    double sum = 0.0;
    long num = slices.size();
    for(long i = 0; i < num; ++i) {
      sum += slices[i].count->getDouble();
    }
    for(long p = 0, i = 0; i < num; ++i) {
      double s = slices[i].count->getDouble()/sum;
      long q = (i == (num-1))? 360: (360*s + p);
      double xx = 2*x;
      double yy = 0.90-i*0.05;
      double cc = 0.03 + 0.9*((num > 1)? ((double)i / (double)num): 0);
      gp("set label \'%s [%f%%]\' at screen %f,%f front", slices[i].label, 100.0*s, xx+0.06, yy);
      gp("set object %d rectangle from screen %f,%f to screen %f,%f fillcolor rgb 'black' front fillstyle solid %f border -1", 2*i+1, xx, yy+0.01, xx+0.05, yy-0.01, cc);
      if((q-p) >= 1) {
        gp("set object %d circle at screen %f,%f size screen %f arc [%d:%d] fillcolor rgb \'black\' front fillstyle solid %f border -1", 2*i+2, x, y, d, p, q, cc);
      }
      p = q;
    }
    gp("set label \'%s [%f]\' at screen %f,%f center", label, sum, 0.5, 0.08);
    gp("unset border");
    gp("unset tics");
    gp("unset key");
    gp("plot x with lines lc rgb \'#ffffff\'");
  }
}

void GStatsPie::reportBinValue() const
{
//  I(H.empty()); // call stop before
//    
//  uint32_t maxKey = 0;
//
//  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
//    Report::binField(it->second);
//    if(it->first > maxKey)
//      maxKey = it->first;
//  }
//  long double div = cumulative; // cummulative has 64bits (double has 54bits mantisa)
//  div /= numSample;
//
//  Report::binField((double)maxKey, (double)div, numSample);
}

void GStatsPie::reportScheme() const
{
//  for(Histogram::const_iterator it=H.begin();it!=H.end();it++) {
//    char nm[100];
//    sprintf(nm, "%s(%u)", name, it->first);
//    Report::scheme(nm, "8");
//  }
//  Report::scheme(name, "{\"max\":8,\"v\":8,\"n\":8}");
}

void GStatsPie::addCounter(GStatsCntr *count, const char *label)
{
  PieSlice ps;
  ps.count = count;
  strcpy(ps.label, label);
  slices.push_back(ps);
}

int64_t GStatsPie::getSamples() const 
{
  int64_t data = 0;
  for(long i = 0; i < slices.size(); ++i) {
    data = slices[i].count->getSamples();
  }

  return data;
}

void GStatsPie::flushValue()
{
  slices.clear();
}
