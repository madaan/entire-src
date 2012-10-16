//sg
#include<stdio.h>
int main()
{

int seats=2,i;
float p_SEAT,p,pval;
int N;
scanf("%d",&N);
while(N--)
{
	p_SEAT=0;
	scanf("%f",&p);
	p=1-p;
	pval=1;
	i=0;
do
{
	pval=pval*p;
	p_SEAT=1-pval;
	i++;
}
while(p_SEAT!=1);
printf("\np_SEAT =1 after %d seats for p=%f\n",i,1-p);
	}
return 0;
}
