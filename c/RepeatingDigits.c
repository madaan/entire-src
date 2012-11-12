//sg
#include<stdio.h>
#include<string.h>
#define debug
//Calculate Distinct Digits
long long MUL(int start,int N)
{
	int i;
	long long res=1;
	
	for(i=0;i<N;i++)
		{
			
			res*=start;
			
			start--;
		}
		#ifdef debug
		printf("\nMUL(%d,%d) returning %lld",start+N,N,res);
		#endif
		return res;
		
}
long long CDD(int firstDigit,char * number,int digitsLeft,int NDigits)
{
	long long int res;
	
	res=firstDigit*MUL(digitsLeft,NDigits-1);
	if(NDigits==1) //base case
	{
		#ifdef debug
	printf("\nCDD ( %d,%s,%d,%d ) returning %lld",firstDigit,number,digitsLeft,NDigits,res);
	#endif
	
		return res+1;
	}
	if(number[1]=='0'||number[1]=='1')
	{
		firstDigit=0;
	}
	else if(number[1]<number[0])
	{
		firstDigit=number[1]-48+1;
		}
	else
	{
			firstDigit=number[1]-48;
	
	}
	res+=CDD(firstDigit,number+1,digitsLeft-1,NDigits-1);
	#ifdef debug
	printf("\nCDD ( %d,%s,%d,%d ) returning %lld",firstDigit,number,digitsLeft,NDigits,res);
	#endif
	return res;
}
int main()
{
	char L[22],R[22];
	long long digits[11],result=0;
	int i,cases=9,ll,lr;
	//initialize
	digits[1]=9;
	for(i=2;i<10;i++)
	{
	digits[i]=digits[i-1]*cases;
	#ifdef debug
	printf("\ndigits[%d]=%lld",i,digits[i]);
	#endif
	cases--;
	}
	//both are same
	digits[10]=digits[9];
	scanf("%d",&cases);
	while(cases--)
	{
	result=0;
	scanf("%s%s",L,R);
	ll=strlen(L);
	lr=strlen(R);
	//if both the numbers are greater than 0, she will never get such a dish
	if(ll>10&&lr>10)
	{
		printf("0\n");
		continue;
	}
	if(lr>10)
	{
		strcpy(R,"9999999999");
		lr=10;
	}
	//straight away add all the intermediate results
	for(i=ll+1;i<lr;i++)
	{
		result+=digits[i];
	}
	//now process the intermediates
	if(ll==lr)
	{
	result=CDD(R[0]-49,R,9,lr)-CDD(L[0]-49,L,9,ll)+1;
	printf("%lld\n",result);
	}
	else
	{
	result+=(digits[ll]-CDD(L[0]-49-1,L,9,ll));
	result+=CDD(R[0]-49,R,9,lr);
	#ifdef debug
	//printf("\n%s : %lld",L,CDD(L[0]-49,L,9,ll));
	//printf("\n%s : %lld\n",R,CDD(R[0]-49,R,9,lr));
	#endif
	printf("%lld\n",result);	
	}
	}
	return 0;
}
