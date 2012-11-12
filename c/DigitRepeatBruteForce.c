//sg
#include<stdio.h>
#include<stdlib.h>
long long checkRep(long long N)
{
	int flag[]={0,0,0,0,0,0,0,0,0,0};
	while(N)
	{
		if(flag[N%10]==1)
		return 0;
		else
		flag[N%10]=1;
		N/=10;
	}	
	return 1;
}
int main(int argc,char *argv[])
{
	long long int a=atoll(argv[1]);
	long long int b=atoll(argv[2]);
	long long i,count=0;
	for(i=a;i<=b;i++)
	{
		if(checkRep(i))
		{
			count++;
		}
	}
	printf("%lld\n",count);
}
