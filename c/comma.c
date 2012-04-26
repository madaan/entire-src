//sg
#include<stdio.h>
#include<ctime>
main()
{
int i;
i=343,1,2,3,4,0;
if(1,2,3,4,0)
{
printf("no");
}
else
{
printf("yes");
}
printf("\103");
printf("\n%d\n",i);
   time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    printf("%d/%d/%d", (now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday);
}
