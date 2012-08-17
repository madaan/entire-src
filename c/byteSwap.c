//sg
#include<stdio.h>
//program to swap bytes of an integer
void printBin(short x)
{
	int i=0;
	while(i<16)
	{
		printf((x&(32768))?"1":"0");
		x=x<<1;
		i++;
		printf((i%8)?"":"\n");
	}
	printf("\n");
}
int main()
{
	short x,temp=0;
	
	char * lb,*hb;
	printf("Enter the number : ");
	scanf("%hd",&x);
	printBin(x);
	//little endian
	lb=(char *)&x;
	hb=lb+1;
	temp|=*lb;
	//now left shift
	temp=temp<<8;
	temp|=*hb;
	printBin(temp);
	return 0;
}	
	
