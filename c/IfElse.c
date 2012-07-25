//sg
#include<stdio.h>
main()
{
if(!printf("Hello"))
{}
else
printf(" World\n");
if(1)
{
printf("Second ");
goto els;
}
else
{
els:
printf("Way\n");
}
}
