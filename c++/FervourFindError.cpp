//sg
//code tested on gcc standard version (ANSI)
#include <iostream>  //iostream.h is obsolete,shouldn't be used  
#include <stdlib.h>
#include<stdarg.h>
//conio.h is non standard ,shouldn't be used
#include<stdio.h> //to be added for printf,file io
#include<stdarg.h> //required for variable argument conversion

FILE *fp;  //capital FILE not small

int vfprf(char *fmt,...)
{
va_list argptr;
int cnt;
va_start(argptr, fmt);
cnt = vfprintf(fp, fmt, argptr);  //wrong version used,need to print to file
va_end(argptr);  //typing mistake
return(cnt);
}

int main(void)
{
char * stop ="damn";
float move = 42.6f;
char * boom ="doomed";

//fp = tpfyl();  //another non standard function perhaps i am substituing it with a call to fopen
fp=fopen("sgt","w");
if (fp == NULL) //NULL IS THE DEFINED MACRO,NOT null
{
perror("tpfyl() call");
exit(1); 
}

vfprf("%s %f %s", stop, move, boom);  //calling the required function
rewind(fp); //used with a filestream
fscanf(fp,"%s %f %s", stop, &move, boom);
printf("%s %f %s\n", stop, move, boom);
fclose(fp); //pclose?
return 0;
//since conio.h is obsolete ,getch() has to be removed
} //end 
