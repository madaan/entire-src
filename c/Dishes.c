	//sg
	#include<stdio.h>
	//what if (x*y)%c becomes way too large? - > 
	// (a*b)%c if a*b can grow very large
	long long int handleLargeMod(long long int a,long long int b,long long int c)
	{
			long long int x=0,y=a%c;
			
		while(b)
		{
			
			if(b%2==1) //final step as well as the first step in case of odd
			{
				x=(x+y)%c;
			
			}
				y=(y*2)%c;
			
			//printf("\ny=%lld b=%lld c=%lld",y,b,c);
			b/=2;
		}
		return x%c;
		
	}
	/*
	 *  a^b%c= 
	 * 
	 */ 
	 
	 long long int abMODc(long long int a,long long int b,long long int c)
	{

		long long int x=1,y=a;
		while(b)
		{
			if(b%2!=0) //final step as well as the first step in case of odd
			{
				x=handleLargeMod(x,y,c);
			}
			
				y=handleLargeMod(y,y,c);
			
			b/=2;
		}
		return x%c;
	}
	/* a=bModc , d=eModc -> (a+d)=(b+e)Modc*/

	int main()
	{
		int T;
		int colors=4;
		long long int N,a,b,res;
		
	//	printf("\n%lld",handleLargeMod(223,23244,15));
	scanf("%d",&T);
		

		while(T--)
		{
		scanf("%lld",&N);
		a=abMODc(colors-1,N,1000000007);
		if(N%2==0)
		{
			b=colors-1;
		}
		else
		{
			b=-(colors-1);
		}
		b=b%(1000000007);
		if(N==1)
		res=4;
		else
		res=(a+b)%(1000000007);
		printf("\n%lld",res);
		}
	return 0;
	}
