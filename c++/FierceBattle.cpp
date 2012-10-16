//sg
#include<stdio.h>
int intC[101],floatC[101];
int chakraDeficit()
{
	int cdef=0;
	for(int i=0;i<=100;i++)
	{
		if(intC[i]<floatC[i])
		{
			cdef+=(floatC[i]-intC[i]);
		}
	}
	return cdef;
}
void refresh()
{
	for(int i=0;i<=100;i++)
	{
		intC[i]=floatC[i]=0;
	}
}
int main()
{	
	int N,ic,fc,val,l;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&ic,&fc);
		while(ic--)
		{
			scanf("%d%d",&val,&l);
			intC[l]+=val;
		}
		while(fc--)
		{
			scanf("%d%d",&val,&l);
			floatC[l]+=val;
		}
		printf("%d\n",chakraDeficit());
		refresh();
	}
	return 0;
}
