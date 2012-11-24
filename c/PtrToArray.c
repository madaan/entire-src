//sg
#include<stdio.h>
void printArr(int (*p)[10])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("\nElement %d = %d",i,*(*p+i));
	}
	printf("\np:%p",p);
	printf("\n*p:%p",*p);
	
}
int main()
{
	int a[11],i;
	for(i=0;i<11;i++)
	{
		a[i]=i;
	}
	printf("\na:%p",a);
	printArr(&a);
	return 0;
}
