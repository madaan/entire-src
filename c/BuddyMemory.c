//sg
#include<stdio.h>
#include<stdlib.h>
unsigned int nearest2(unsigned int req)
{
req--;
req|=req>>1;
req|=req>>2;
req|=req>>4;
req|=req>>8;
req|=req>>16;
req++;
return req;
}
int main()
{
	char req[100];
	int N,i=0;
	
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",req);
		i=0;
		while(req[i]!='K')
		{
			i++;
		}
		req[i]='\0';
		printf("%u",nearest2((unsigned int)atoi(req)));
		printf("K\n");
	}
return 0;
}

