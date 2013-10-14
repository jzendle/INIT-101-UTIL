#ifndef LOGGER_H
#include "Logger.h"
#include "Timer.h"

#include <stdio.h>
#include <stdarg.h>

void logit(FILE *fp, const char *format, va_list ap) {
    vfprintf(fp, format, ap);
}

void info(const char *msg) {
    char time[256];
    char buf [1024];
    time_to_string(time, sizeof time);
    snprintf(buf, sizeof (buf), "%s INFO: %s\n", time, msg);
    fprintf(stdout, "%s", buf);
}

void err(const char *msg) {
    char time[256];
    char buf [1024];
    time_to_string(time, sizeof time);
    snprintf(buf, sizeof (buf), "%s ERROR: %s\n", time, msg);
    fprintf(stderr, "%s", buf);
}

void errv(const char *format, ...) {
    char time[256];
    time_to_string(time, sizeof time);
    char buf[1024];
    snprintf(buf, sizeof (buf), "%s ERROR: %s", time, format);

    va_list ap;
    va_start(ap, format);
    logit(stderr, buf, ap);
    va_end(ap);
}

void infov(const char *format, ...) {
     char time[256];
    time_to_string(time, sizeof time);
    char buf[1024];
    snprintf(buf, sizeof (buf), "%s ERROR: %s", time, format);
    va_list ap;
    va_start(ap, format);
    logit(stdout, buf, ap);
    va_end(ap);
}

#endif