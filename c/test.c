//sg
#include <stdio.h>


int main(int argc, char *argv[])
{
	static int a[1<<20]={};
	int i;
	for(i=0;i<100;i++)
	printf("%d ",a[i]); 
    return 0;  
}
