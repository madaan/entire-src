//sg
#include<stdio.h>
#define swap(t,a,b) t temp;temp=a,a=b,b=temp;
main()
{
float a=2,b=3;
float * p,*q;
p=&a;q=&b;
printf("%f and %f",*p,*q);
swap(float * , p,q);
printf("\n%f and %f\n",*p,*q);
}
