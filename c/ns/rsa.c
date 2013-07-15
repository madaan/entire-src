//sg
#include <stdio.h>
int gcd(int a, int b) 
{
	int temp;
	while(b > 0) {
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int abmodn(int a, int b, int n) 
{
	int i = 0;
	int res = 1;
	for(i = 0; i < b; i++) {
		res = (res*a)% n;
	}
	return res % n;
}

int mulInv(int a, int n) 
{
	int originalN = n;
	int temp, q;
	int x = 0, lx = 1, ly = 0, y = 1;
	while(n) {
		q = a / n;
		temp = a;
		a = n;
		n = temp % n;
		temp = x;
		x = lx - x * q;
		lx = temp;
		temp = y;
		y = ly - y * q;
		ly = temp;
	}
	if (lx < 0) {
		lx = originalN + lx;
	}
	return lx;
}
int main() 
{
	int p, q, N, phi;
	int enc, dec, num;
	printf("Enter p and q : ");
	scanf("%d%d", &p, &q);
	N = p * q;
	phi = (p - 1) * (q - 1);
	int e = 2, d = 2;
	while(gcd(e, phi) != 1) {
		e++;
	}

    e = 17;
	d = mulInv(e, phi);
	printf("%d %d %d\n", e, d, phi);
	printf("Enter the number to be encrypted : ");
	scanf("%d", &num);
	enc = abmodn(num, e, N);
	dec = abmodn(enc, d, N);
	printf("Value after enc = %d\nValue after dec = %d\n%d\n%d", enc, dec, abmodn(65, 17, 3233), abmodn(2790, 2753, 3233));
	
	return 0;
}
