//sg
#include<stdio.h>
#include<ncurses.h>
int f(int *a,int n)
{
	if(n<=0)
	{
		return 0;
	}
	else if(*a%2==0)
	return *a+f(a+1,n-1);
	else
	return *a-f(a+1,n-1);
}
int main()
{
int i,j,t;      
 /*
	int a[]={12,7,13,4,11,6};
	int * callocarr,*mallocarr,i;
	callocarr=(int *)calloc(10,sizeof(int));
	mallocarr=(int*)malloc(10*sizeof(int));
	for(i=0;i<10;i++)
	printf("\n%d",callocarr[i]);
	for(i=0;i<10;i++)
	printf("\n%d",mallocarr[i]);
	
printf("%d\n%d\n%d",sizeof(long),sizeof(int),sizeof(short int));
int a=10;
int res=a++ + ++a + ++a +a;
printf("\n%d",res);
*/
for(i=0;i<100000;i++)
for(j=0;j<100000;j++)
{
for(t=0;t<1000;t++)
{}
}
return 0;
}
