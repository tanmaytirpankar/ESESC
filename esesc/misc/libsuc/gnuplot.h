#ifndef GNUPLOT_H
#define GNUPLOT_H
#include <stdio.h>
#include <cstdarg>

class GNUPlot {
private:
    FILE *gnuplotpipe;
public:
    GNUPlot() {
        gnuplotpipe = popen("gnuplot -persist", "w");
        if(gnuplotpipe == NULL) {
            printf("ERROR: could not create a pipe to GNUPLOT!\n");
        }
    }
    ~GNUPlot() {
        fprintf(gnuplotpipe, "exit\n");
        pclose(gnuplotpipe);
    }
    bool isOpen() {
        return (gnuplotpipe != NULL);
    }
    bool operator() (const char* fmt...) {
        char cmd[1<<20];
        char *ptr = cmd;
        va_list args;
        va_start(args, fmt);
        while(*fmt != '\0') {
            if(*fmt == '%') {
                ++fmt;
                *ptr = '\0';
                if(fmt[0] == '%') {
                    *(ptr++) = '%';
                }
                else if(fmt[0] == 'c') {
                    *(ptr++) = va_arg(args, char);
                }
                else if(fmt[0] == 's') {
                    sprintf(cmd, "%s%s", cmd, va_arg(args, char*));
                    for(; *ptr; ++ptr);
                }
                else if(fmt[0] == 'd') {
                    sprintf(cmd, "%s%ld", cmd, va_arg(args, long));
                    for(; *ptr; ++ptr);
                }
                else if(fmt[0] == 'f') {
                    sprintf(cmd, "%s%f", cmd, va_arg(args, double));
                    for(; *ptr; ++ptr);
                }
                else {
                    printf("ERROR: unknown format '%%%c' in '%s'!\n", fmt[0], fmt);
                    return false;
                }
                ++fmt;
            }
            else {
                *(ptr++) = *(fmt++);
            }
        }
        *ptr = '\0';
        va_end(args);

        fprintf(gnuplotpipe, "%s\n", cmd);
        fflush(gnuplotpipe);
        //printf("\tGNUPLOT :: %s\n", cmd);

        return true;
    }

};
#endif
