/* 
 * File:   logger.h
 * Author: jzendle
 *
 * Created on September 30, 2013, 6:46 PM
 */

#ifndef LOGGER_H
#define	LOGGER_H

#include "Logger.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef	__cplusplus
extern "C" {
#endif

    void info(const char *msg);
    
    void infov(const char *str, ... );
    
    void err(const char *msg);
    
    void errv(const char *msg, ... );


#ifdef	__cplusplus
}
#endif

#endif	/* LOGGER_H */

