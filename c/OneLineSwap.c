//sg
#include<stdio.h>
#define SWAP(x,y) x^=y^=x^=y;
int main()
{
	int x=3,y=4;
	printf("x=%d,y=%d\n",x,y);
	SWAP(x,y);
	printf("x=%d,y=%d\n",x,y);
	return 0;
}
