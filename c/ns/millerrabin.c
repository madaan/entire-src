//sg
#include <stdio.h>
#include <stdlib.h>
int abmodn(int a, int b, int n) 
{
	int i = 0;
	int res = 1;
	for(i = 0; i < b; i++) {
		res = (res*a)% n;
	}
	return res % n;
}

//for an odd p, p - 1 can be rep as 2^k*q
void getKQ(int p, int *k, int *q)
{
	if(p % 2 == 0) {
		return;
	}
	p = p - 1;
	int kt = 0;
	while(!(p & 1)) {
		kt++;
		p = p >> 1;
	}
	*k = kt;
	*q = p;
}

int main()
{
	int k, q, n, t, ki, pt, a, found = 0;
	
	printf("Enter the number whose primality has to be tested : ");
	scanf("%d", &n);
	if(n % 2 == 0) {
		printf("Composite\n");
		return 0;
	}
	printf("Enter the number of iterations you want to perform : ");
	scanf("%d", &t);
	
	getKQ(n, &k, &q);
	a = 2;
	srand(time(NULL));
	while(t-- && (a < n - 1)) {
	a++;
	//a = rand() % (n-2) + 1;
	if (abmodn(a, q, n) == 1) {
		printf("Inconclusive\n");
		continue;
	}
	for(ki = 0; ki < k; ki++) {
		pt = (1 << ki) * q; //power term
		if(abmodn(a, pt, n) == n - 1) {
			printf("Inconclusive\n");
			found = 1;
			break;
		}
	}
	if(found == 1) {
		found = 0;
		continue;
	}
	printf("Composite\n");
	return 0;
	
	}
	return 0;
}
	
