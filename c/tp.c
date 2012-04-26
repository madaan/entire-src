//sg
#include<stdio.h>
main()
{

unsigned int a,b,carry,carryCount,temp;
scanf("%u%u",&a,&b);
while((a!=0)&&(b!=0))
{
carry=0;
carryCount=0;
while((a)&&(b))
{
temp=(a%10)+(b%10)+carry;
if(temp>=10)
{
carryCount++;
carry=1;
}
else
{
carry=0;
}
a/=10;
b/=10;
if((!a)&&(b))
{
if(((b%10)+carry)>=10)
{
carryCount++;
break;
}
}

if((a)&&(!b))
{
if(((a%10)+carry)>=10)
{
carryCount++;
break;
}
}
}
switch(carryCount)
{
case 0:
puts("No carry operation.\n");
break;
case 1:
puts("1 carry operation.\n");
break;
default :
printf("%u carry operations.\n",carryCount);
}
scanf("%u%u",&a,&b);
}
	
}
