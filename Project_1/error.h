/*
 *  Soubor:      error.h
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       18.3.2018
 */


#ifndef _ERRORH_
#define _ERRORH_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#endif
