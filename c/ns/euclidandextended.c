//sg
#include <stdio.h>
#include <stdlib.h>
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

int extendedEuclid(int a, int b) 
{
	int lx = 1, x = 0, ly = 0, y = 1;
    int bb = b;
	int temp, q;
	while(b) {
        printf("a = %-5d b = %-5d x = %-5d y = %-5d lx = %-5d ly = %-5d\n",a, b, x, y, lx, ly); 
		q = a / b;
		temp = a;
		a = b;		
		b = temp % b;
		temp = x;
		x = lx - x * q;
		lx = temp;
		temp = y;
		y = ly - y * q;
		ly = temp;
	}
    if(lx < 0) {
        return bb + lx;
    }
	return lx;
}
int main(int a, char *v[]) {
    if(a == 3) {
	printf("%d\n", extendedEuclid(atoi(v[1]), atoi(v[2])));
    }
    return 0;
}
