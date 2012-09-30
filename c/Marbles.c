//sg
#include<stdio.h>
#include<math.h>
long long gcd(long long a,long long b)
{
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}
void divGCD(long long * a,long long * b)
{
	long long g=gcd(*a,*b);
	*a/=g;
	*b/=g;
}
long long C(long long n, long long k)
{
	long long num=1,den=1,i,currN,currD;
	if(k>n-k)
	{
		k=n-k;
	}
	for(i=1;i<=k;i++)
	{
		currN=n-i+1;
		currD=i;
		divGCD(&currN,&currD);
		divGCD(&num,&currD);
		divGCD(&den,&currN);
		num*=currN;
		den*=currD;
	}
	//printf("\nnum=%lld den=%lld",num,den);
	return  num/den;
		
	}

int main()
{
	int cases;
	long long n,k;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%lld %lld",&n , &k);
	printf("%lld\n",C(n-1,k-1));
	}
	return 0;
}
