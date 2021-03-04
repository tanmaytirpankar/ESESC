// Contributed by Jose Renau
//                Basilio Fraguela
//                James Tuck
//                Smruti Sarangi
//                James Tuck
//                Luis Ceze
//
// The ESESC/BSD License
//
// Copyright (c) 2005-2013, Regents of the University of California and 
// the ESESC Project.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   - Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
//   - Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
//   - Neither the name of the University of California, Santa Cruz nor the
//   names of its contributors may be used to endorse or promote products
//   derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef GSTATSD_H
#define GSTATSD_H

#include "estl.h" // hash_map

#include <list>
#include <stdarg.h>
#include <vector>

#include "callback.h"
#include "nanassert.h"

class GStats_strcasecmp {
public:
  inline bool operator()(const char* s1, const char* s2) const {
    return strcasecmp(s1, s2) == 0;
  }
};


class GStats {
private:
  typedef HASH_MAP<const char *, GStats *, HASH<const char*>, GStats_strcasecmp > Container;
  typedef HASH_MAP<const char *, GStats *, HASH<const char*>, GStats_strcasecmp >::iterator ContainerIter;
  static Container *store;

protected:
  char *name;

  char *getText(const char *format, va_list ap);
  void subscribe();
  void unsubscribe();

public:
  int32_t gd;

  static void report(const char *str);
  static void reportBin();
  static void reportSchema();
  
  static GStats *getRef(const char *str);

  GStats();
  virtual ~GStats();

  void prepareTrace();

  virtual void reportValue() const = 0;
  virtual void reportBinValue() const = 0;
  virtual void reportScheme() const = 0;

  virtual void flushValue();
  static void flush();

  virtual double getDouble() const {
    MSG("getDouble Not supported by this class %s",name);
    return 0;
  }

  const char *getName() const { return name; }
  virtual int64_t getSamples() const = 0;
};

class GStatsCntr : public GStats {
private:
  double data;

protected:
public:
  GStatsCntr(const char *format,...);

  GStatsCntr & operator += (const double v) {
    data += v;
    return *this;
  }

  void add(const double v, bool en = true) {
    data += en ? v : 0;
  }
  void inc(bool en = true) {
    data += en ? 1 : 0;
  }

  void dec(bool en) {
    data -= en ? 1 : 0;
  }

  double  getDouble() const;
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsAvg : public GStats {
private:
protected:
  double data;
  int64_t nData;
public:
  GStatsAvg(const char *format,...);
  GStatsAvg() { }

  void    reset() { data = 0; nData = 0; };
  double  getDouble() const;

  virtual void sample(const double v, bool en);
  int64_t getSamples() const;

  virtual void reportValue() const;
  virtual void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsMax : public GStats {
private:
protected:
  double maxValue;
  int64_t nData;

public:
  GStatsMax(const char *format,...);

  void sample(const double v, bool en);
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsHist : public GStats {
private:
protected:
  
  typedef HASH_MAP<uint32_t, double> Histogram;

  double numSample;
  double cumulative;

  Histogram H;
  char pfname[256];
  char xlabel[256];
  char ylabel[256];
  bool doPlot;

public:
  GStatsHist(const char *format,...);
  GStatsHist() { }

  void sample(bool enable, uint32_t key, double weight=1);
  void setPFName(const char *pfname) { strcpy(this->pfname, pfname); }
  void setPlotLabels(const char *xlabel, const char *ylabel) { doPlot = true; strcpy(this->xlabel, xlabel); strcpy(this->ylabel, ylabel); }
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsHeat : public GStats {
private:
protected:
  
  typedef HASH_MAP<uint32_t, double> Histogram;

  double numSample;
  double cumulative;

  Histogram H;
  char pfname[256];
  char xlabel[256];
  char ylabel[256];
  bool doPlot;

  bool (*isBorder)(unsigned long, unsigned long);
  unsigned long (*computeDimX)(void);
  unsigned long (*computeDimY)(void);
  unsigned long (*computeX)(unsigned long);
  unsigned long (*computeY)(unsigned long);

public:
  GStatsHeat(const char *format,...);
  GStatsHeat() { }

  void sample(bool enable, uint32_t key, double weight=1);
  void setPFName(const char *pfname) { strcpy(this->pfname, pfname); }
  void setPlotFunctions(bool (*isBorder)(unsigned long, unsigned long), unsigned long (*computeDimX)(void), unsigned long (*computeX)(unsigned long), unsigned long (*computeDimY)(void), unsigned long (*computeY)(unsigned long)) {
    doPlot = true;
    this->isBorder = isBorder;
    this->computeDimX = computeDimX;
    this->computeDimY = computeDimY;
    this->computeX = computeX;
    this->computeY = computeY;
  }
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsSack : public GStats {
private:
protected:

  std::vector<long> data;
//  typedef HASH_MAP<uint32_t, double> Histogram;
  typedef std::map<uint32_t, double> Frequency;

//  double numSample;
//  double cumulative;

//  Histogram H;
  char pfname[256];
  char xlabel[256];
  char ylabel[256];
  bool doPlot;

public:
  GStatsSack(const char *format,...);
  GStatsSack() { }

  long getMonitor() { data.push_back(0); return data.size() - 1; }
  void setMonitor(unsigned long index, long value) { if(index < data.size()) { data[index] = value; } }
  void incMonitor(unsigned long index) { if(index < data.size()) { data[index]++; } }
  void decMonitor(unsigned long index) { if(index < data.size()) { data[index]--; } }
  //void sample(bool enable, uint32_t key, double weight=1);
  void setPFName(const char *pfname) { strcpy(this->pfname, pfname); }
  void setPlotLabels(const char *xlabel, const char *ylabel) { doPlot = true; strcpy(this->xlabel, xlabel); strcpy(this->ylabel, ylabel); }
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsFreq : public GStats {
private:
protected:
  
  typedef HASH_MAP<uint32_t, double> Histogram;
  typedef std::map<uint32_t, double> Frequency;

  double numSample;
  double cumulative;
  uint32_t bucketSize;

  Histogram H;
  char pfname[256];
  char xlabel[256];
  char ylabel[256];
  bool doPlot;
  bool doBucket;

public:
  GStatsFreq(const char *format,...);
  GStatsFreq() { }

  void sample(bool enable, uint32_t key, double weight=1);
  double getValue(uint32_t key) {
    if(H.find(key)==H.end())
      return 0.0;
    return H[key];
  }
  void setPFName(const char *pfname) { strcpy(this->pfname, pfname); }
  void setPlotLabels(const char *xlabel, const char *ylabel) { doPlot = true; strcpy(this->xlabel, xlabel); strcpy(this->ylabel, ylabel); }
  void setBucketSize(uint32_t size) { doBucket = (size > 0); bucketSize = size; }
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsTrac : public GStats {
private:
protected:
  
  std::vector<uint32_t> Index;
  std::vector<double> Value;

  double numSample;
  double lastSample;
  double maxSample;

  char pfname[256];
  char xlabel[256];
  char ylabel[256];
  bool doPlot;

public:
  GStatsTrac(const char *format,...);
  GStatsTrac() { }

  void sample(bool enable, uint32_t key, double value);
  void setPFName(const char *pfname) { strcpy(this->pfname, pfname); }
  void setPlotLabels(const char *xlabel, const char *ylabel) { doPlot = true; strcpy(this->xlabel, xlabel); strcpy(this->ylabel, ylabel); }
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

class GStatsPie : public GStats {
private:
protected:
  
  typedef struct _PieSlice {
    char label[512];
    GStatsCntr *count;
  } PieSlice;

  std::vector<PieSlice> slices;
  char pfname[256];
  char label[256];

public:
  GStatsPie(const char *format,...);
  GStatsPie() { }

  void addCounter(GStatsCntr *count, const char *title);
  void setPFName(const char *pfname) { strcpy(this->pfname, pfname); }
  void setPlotLabel(const char *label) { strcpy(this->label, label); }
  int64_t getSamples() const;

  void reportValue() const;
  void reportBinValue() const;
  void reportScheme() const;

  void flushValue();
};

#endif   // GSTATSD_H
