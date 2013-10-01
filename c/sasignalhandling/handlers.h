//sg
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef HANDLERS
#define HANDLERS
void ctrlc_handler();
void ctrlbackspace_handler();
void divzero_handler();
void alarm_handler();
#endif

