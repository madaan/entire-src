//sg
#include<stdio.h>
int main()
{
int N,i;
int sum,min,temp,t;
scanf("%d",&t);
while(t--)
{
	sum=0;
	min=100000;
scanf("%d",&N);
i=N;
while(i--)
{
	scanf("%d",&temp);
	sum+=temp;
	if(temp<min)
	{min=temp;}
}	
printf("%d\n",sum-N*min);
}
return 0;	
}

