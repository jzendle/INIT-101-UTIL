#ifndef TIMER_H

#include "Timer.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

char  *time_to_string(char *buffer, int len) {
  
    struct timeval tv;
    time_t now;
    char msBuf[256];

    gettimeofday(&tv, 0);

    now = tv.tv_sec;

    strncpy(buffer, ctime(&now), len);
    
    //     Buffer now contains format similar to "Sun Oct 13 18:04:40 2013\\n"
    //     We want to place the microsecond field right after the seconds field (40 in this case)
    //     so we will truncate the string at the space after the zero in 40.
    //     Walk backward from end of string until we find the first space and replace it with a NULL

    char *end = &buffer[strlen(buffer)];
    
    for ( ; end--; end == &buffer[0]) {
        if ( *end == 0x20) {
            *end = 0;
            break;
        }
    }
   
    // stringify the micro seconds field
    snprintf(msBuf, len, ".%06ld", tv.tv_usec);
    
    // concat the two.
    strncat(buffer, msBuf, len);
    
    
    return buffer;

}


#endif
