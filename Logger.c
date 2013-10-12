#ifndef LOGGER_H
#include "Logger.h"

#include <stdio.h>
#include <stdarg.h>

void logit(FILE *fp, const char *format, va_list ap) {
    vfprintf(fp, format, ap);
}

void info(const char *msg) {
    fprintf(stdout, "INFO: %s\n", msg);
}

void err(const char *msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
}

void errv(const char *format, ...) {
    char buf[1024];
    snprintf(buf, sizeof (buf), "ERROR: %s", format);
    va_list ap;
    va_start(ap, format);
    logit(stderr, buf, ap);
    va_end(ap);
}

void infov(const char *format, ...) {
    char buf[1024];
    snprintf(buf, sizeof (buf), "INFO: %s", format);
    va_list ap;
    va_start(ap, format);
    logit(stdout, buf, ap);
    va_end(ap);
}

#endif