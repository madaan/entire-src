#include<stdio.h>

unsigned int getPali(unsigned int t)
{
unsigned int res=0;
while(t)
{
res*=10;
res+=t%10;
t/=10;
}
return res;
}
main()
{
unsigned int a,b,cases;
scanf("%u",&cases);
while(cases--)
{
scanf("%u%u",&a,&b);
printf("%u\n",getPali(getPali(a)+getPali(b)));
}
}
