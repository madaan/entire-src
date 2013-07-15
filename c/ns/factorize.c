//sg
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int divisor = 2;
	int times = 0;
	printf("%d = ", n);
    while(n != 1) {
		while(n % divisor == 0) {
			times++;
			n /= divisor;
		}
		if(times != 0)
		printf("(\a%d ^ %d) * ", divisor, times);
		divisor++;
		times = 0;
	}
	printf("(1)\n");
	return 0;
}
			
		
