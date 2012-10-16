//sg
#include<stdio.h>
typedef struct 
{
	int x,y,taken;
}pos;

int main()
{
int h,w,i,j,done=0;
long long a[300][300],max=0;
long long temp;
int posrow[300];
int pC=0,pc=0,pr=0;
int csize=1,rsize=0;

scanf("%d%d",&h,&w);
for(i=0;i<h;i++)
{
	for(j=0;j<w;j++)
	{
		scanf("%lld",&a[i][j]);
		if(a[i][j]>0&&a[i][j]>max)
		{
			max=a[i][j];
			
			pc=j;
			pr=i;
		}
		
	}
	
}
printf("1 1\n%d\n%d",pr,pc);
/*
i=0;
while(i<h)//still got positive locs
{
	if(a[i][pc]>0)
	{
		posrow[rsize]=i;
		rsize++;
	}
	i++;
}
		
printf("%d 1\n",rsize);
for(i=0;i<rsize;i++)
{
	printf("%d ",posrow[i]);
}
printf("\n%d",pc);
*/
return 0;
}


