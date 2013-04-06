//sg
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
void dump(int *a)
{
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void merge(int * arr,int l,int m,int r)
{
	int na=m-l+1;
	int nb=r-m;
	int i=0,k=0,j;
	int * a=(int *)malloc(sizeof(int)*na);
	int * b=(int *)malloc(sizeof(int)*nb);
	for(i=0;i<na;i++)
	{
		a[i]=arr[i+l];
	}
	a[i]=MAX;
	for( i=0;i<nb;i++)
	{
		b[i]=arr[i+m+1];
	}
	b[i]=MAX;
	i=j=0;
	for(k=l;k<=r;k++)
	{
		if(a[i]<b[j])
		{
			arr[k]=a[i];
			i++;
		}
		else 
		{
			arr[k]=b[j];
			j++;
		}
	}
}
void mergeSort(int * arr,int l,int r)
{
	int q;
	if(l<r)
	{
		q=(l+r)/2;
		dump(arr);
		mergeSort(arr,l,q);
		mergeSort(arr,q+1,r);
		merge(arr,l,q,r);
	}
}

int main()
{
	int arr[]={8,7,6,5,4,3,2,1};
	dump(arr);
	
	mergeSort(arr,0,7);
	dump(arr);
	return 0;
}
