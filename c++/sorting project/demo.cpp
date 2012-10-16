//sg
#include "NumberReader.cpp"
#include<iostream>
using namespace std;

int partition(int e[],int k,int r)
{
	int i,j,x;
	x=e[k];
	int temp;
	i=k;
	//i+1 to j are all > pivot
	for(j=k+1;j<=r;j++)
	{
		if(e[j]<x)
		{
			i++;
			temp=e[i];
			e[i]=e[j];
			e[j]=temp;
		}
	}
			temp=e[k];
			e[k]=e[i];
			e[i]=temp;
			return i;
}
void quickSort(int e[],int l,int r)
{
	if(l<r)
	{
		int q=partition(e,l,r);
		quickSort(e,l,q-1);
		quickSort(e,q+1,r);
	}	
}

int main()
{
	char filename[]={"nums"};
	const int length=10;
	NumberReader nr(filename,length);
	nr.printNumbers();
	quickSort(nr.getArray(),0,length-1);
	cout<<"After Sorting \n";
	nr.printNumbers();
	return 0;
}
