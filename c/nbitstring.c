//sg
#include<stdio.h>
int l;

int a[10];
void nbit(int n)
{
int i;
if(n==0)
{
for(i=0;i<l;i++)
printf("%d",a[i]);
printf("\n");
}
else{
a[n-1]=0;
nbit(n-1);
a[n-1]=1;
nbit(n-1);

}
}
main()
{
int n;
scanf("%d",&n);
l=n;
nbit(n);
}
