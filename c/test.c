//sg
#include <stdio.h>
#include<unistd.h>

int main()
{
	if(1)
	{
	printf("Hello");
	goto evil;
	}
	else
	{evil:
	printf(" World");
	}
		return 0;
}
