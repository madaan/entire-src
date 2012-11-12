//sg
#include<stdio.h>
 unsigned int ARR[8110];
void init()
{
	int sweep=0,iter=0,iterCurr;
	unsigned int powTerm=5,sweepTerm;
	for(;iter<8000;iter++)
	{
		ARR[iter]=powTerm;
		sweep=0;
		iterCurr=iter;
		sweepTerm=0;
		while(sweep<iterCurr&&iter<=8100)
		{
			sweepTerm=ARR[sweep++];
			iter++;
			ARR[iter]=powTerm+sweepTerm;
		}
		powTerm*=5;
		
	}	
}
int main()
{
	init();
	int t,n,i;
	scanf("%d",&t);
	i=0;
	while(i++<t)
	{
		scanf("%d",&n);
		//printf("Case#%d\n%d\n",i,ARR[n-1]);
		printf("%d\n",ARR[n-1]);
	}
	return 0;
}
