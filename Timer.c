#ifndef TIMER_H

#include "Timer.h"
#include <time.h>
#include <string.h>

char *time_to_string(char *writeto) {
    if ( writeto == NULL) return;
    
    time_t timer;
    int len = strlen(writeto);
    struct tm *tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(writeto, len, "%Y:%m:%d%H:%M:%S", tm_info);
    
    return writeto;
  
}

#endif
