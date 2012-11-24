#include<stdio.h>
#include<string.h>
int main()
{
char *a,*b,c[10],d[10];
a=b;
b=c;
char * ap="some text";
char bp[]="some text";
bp=c;
ap[3]=23;
}
