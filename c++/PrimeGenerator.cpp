//sg
//sg
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
/*
 * function that checks whether a number is 
 * prime  or not.
 * 
 * return : true or false depending on whether the
 * number is prime.
 */
bool isPrime(long n)
{
	if((n==2)||(n==3)||(n==5)||(n==7))
	{
		return true;
	}
	if((n%2==0)||(n==1)||(n%3==0)||(n%5==0)||(n%7==0))
	{
	return false;
	}
	
	if((n>10)&&(n%10==5))	
	{
		return false;
	}
	long sn=sqrt(n);
	for(int i=2;i<=sn;i++)
	{
		if(n%i==0)
		{
		
			return false;
		}
	}
	return true;
}
//calculating a^b%c
int mod(int a,int b,int c)
{
	
}
main()
{
	long l,u;
	cin>>l>>u;
	for(long i=l;i<=u;i++)
	{
		if(isPrime(i))
		{
			cout<<i<<"\n";
		}
	}
}
