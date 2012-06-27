//sg
#include<stdio.h>
main()
{
int l,i,r,a[10];
l=0;
r=9;
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
while(l<r)
{
if(a[l]+a[r]==10)
{
printf("%d %d",a[l],a[r]);
break;
}
else if(a[l]+a[r]>10)
r--;
else
l++;
}
}
