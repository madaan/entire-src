//sg
#include<iostream>
using namespace std;
const int MAX=100;
class MaxSubsequence
{
int noEle;
int arr[MAX];
public:
MaxSubsequence(int n)
{
	if(n>100)
	{
		noEle=99;
	}
	noEle=n;
}
void readInput()
{
	for(int i=0;i<noEle;i++)
	{
		cin>>arr[i];
	}
}
int getMaxSequence()
{
	int L[MAX]={0};
	
	int max=0;
	L[0]=1;
	for(int i=1;i<noEle;i++)
	{
		for(int j=0;j<i;j++)
		{
			// now check for this j
			if((arr[i]>arr[j])&&(L[i]<L[j]+1))
			{
				L[i]=L[j]+1;
			}
		}
	}
	for(int i=0;i<noEle;i++)
	{
		if(L[i]>max)
		max=L[i];
	}
	return max;
}
};
int main()
{
	MaxSubsequence msq(5);
	msq.readInput();
	cout<<endl<<+msq.getMaxSequence()<<endl;
	return 0;
}
