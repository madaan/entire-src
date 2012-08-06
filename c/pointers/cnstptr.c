//sg
#include<stdio.h>
main()
{
char * a="aman";
char const * ptr=a;
ptr[2]='a';
// This will cause a run time error : 
//*(a+1)='3';
printf("%s\n",a);
}

