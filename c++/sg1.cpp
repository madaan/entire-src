//sg
#include <iostream>  //iostream.h is obsolete,shouldn't be used  
#include <stdlib.h>
#include<stdarg.h>
//conio.h is non standard ,shouldn't be used
#include<stdio.h> //to be added for printf
file *fp;

int vfprf(char *fmt, …)
{
va_list argptr;
int cnt;
va_start(argptr, fmt);
cnt = vprintf(fp, fmt, argptr);

v_end(agptr);

return(cnt);
}

int main(void)
{
char *stop = "damn";
float move = 42.6f;
char *boom = "doomed";

fp = tpfyl();
if (fp == NULL) //NULL IS THE DEFINED MACRO,NOT null
{
perror("tpfyl() call");
exit(1); 
}

vfpf("%s %f %s", stop, move, boom);
rewind(tpm);
fscanf(fp,"%s %f %s", stop, &move, boom);
printf("%s %f %s\n", stop, move, boom);
pclose(fp);
return 0;
//since conio.h is obsolete ,getch() has to be removed
} //end
