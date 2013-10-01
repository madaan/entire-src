//sg
#include "handlers.h"
#include <time.h>
void ctrlc_handler() 
{
    printf("Received CTRL + C, press CTRL + \\ to exit\n");
    //reinstall the handler
    signal(SIGINT, ctrlc_handler);
}

void ctrlbackspace_handler()
{
    printf("\nBye-Bye!\n");
    exit(0);
}

void divzero_handler()
{
    printf("Illegal operation : Division by zero\n\
           check your divisors :)\n");
    exit(-1);
    //   signal(SIGFPE, divzero_handler);
} 

void alarm_handler()
{

    time_t rawtime;
    struct tm * timeinfo;
    FILE *f = fopen("log.txt", "a+");
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    fprintf (f, "##LOG UPDATION##\n\nCurrent local time and date: %s\n", asctime (timeinfo) );
    signal(SIGALRM, alarm_handler);
    fclose(f);
}


