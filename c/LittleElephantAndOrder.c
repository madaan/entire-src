//sg
#include<stdio.h>
void printOp(int ns,int nf)
{
	while(ns)
	{
		printf("7");
		ns--;
	}
	while(nf)
	{
		printf("4");
		nf--;
	}
	printf("\n");
}
		
int main()
{
	int f1,f2,s1,s2,lf1,lf2,ls1,ls2,os,of,N,l1,l2;
	char ch;
	
	scanf("%d\n",&N);
	
	while(N--)
	{
		f1=f2=s1=s2=lf1=lf2=ls1=ls2=os=of=l1=l2=0;
	//	printf("\nf1=%d,f2=%d,s1=%d,s2=%d,lf1=%d,lf2=%d,ls1=%d,ls2=%d,os=%d,of=%d\n	",f1,f2,s1,s2,lf1,lf2,ls1,ls2,os,of);
		
	while((ch=fgetc(stdin))!=10)
	{
		if(ch<'4')
		{
			lf1++;	
		
		}
		else if(ch<'7'&&ch>'4') 
		{
			ls1++;
		}
		if(ch=='7')
		{
			s1++;
		}
		else if(ch=='4')
		{
			f1++;
		}
		l1++;
		
	}
	l2=l1;
		while((ch=fgetc(stdin))!=10)
	{
		if(ch<'4')
		{
			lf2++;
			
		}
		else if(ch<'7'&&ch>'4')
		{
			
			ls2++;
		}
		if(ch=='7')
		{
			s2++;
		}
		else if(ch=='4')
		{
			f2++;
		}
		
	}
	#ifdef debug
	printf("\nf1=%d,f2=%d,s1=%d,s2=%d,lf1=%d,lf2=%d,ls1=%d,ls2=%d,os=%d,of=%d\n	",f1,f2,s1,s2,lf1,lf2,ls1,ls2,os,of);
	#endif
	//update the characteristics to reflect that a character has been
	//taken
	//7 taken
	while(s1&&ls2&&l2&&l1)
	{
		s1--;
		ls2--;
		os++;
		l2--;
		l1--;

	}
	while(s1&&lf2&&l2&&l1)
	{
		s1--;
		lf2--;
		os++;
		l2--;
		l1--;
	}
	while(s2&&ls1&&l2&&l1)
	{
		s2--;
		ls1--;
		os++;
		l1--;
		l2--;
	}
	#ifdef debug
	printf("\nf1=%d,f2=%d,s1=%d,s2=%d,lf1=%d,lf2=%d,ls1=%d,ls2=%d,os=%d,of=%d\n	",f1,f2,s1,s2,lf1,lf2,ls1,ls2,os,of);
	#endif
	while(s2&&lf1&&l2&&l1)
	{
		s2--;
		lf1--;
		os++;
		l1--; 
		l2--;
	}
	while(f1&&lf2&&l2&&l1)
	{
		f1--;
		lf2--;
		of++;
		l2--;
		l1--;
	}
	
	while(f2&&lf1&&l2&&l1)
	{
		f2--;
		lf1--;
		of++;

		l1--;
		l2--;
	}
	//now adjust the 7s and 4s
	//take 7s of 1 with 4s of 2
	while(l1&&s1&&f2&&l2)
	{
		l1--;
		os++;
		s1--;
		f2--;
		l2--;
	}
	//take 7s of 2 with 4s of 1
	while(l2&&s2&&f1&&l1)
	{
		l1--;
		os++;
		s2--;
		f1--;
		l2--;
	}
	//take 7s of 1 with 7s of 2
	while(l1&&l2&&s1&&s2)
	{
		l1--;
		l2--;
		s1--;
		s2--;
		os++;
		
		
	}
	//take 4s of 1 with 4s of 2
	while(l1&&f1&&f2&&l2)
	{
		of++;
		f1--;
		f2--;
		l2--;
		l1--;
		
	}
	//printf("\n%d os=%d of=%d",N,os,of);
	printOp(os,of);
}

return 0;
}
