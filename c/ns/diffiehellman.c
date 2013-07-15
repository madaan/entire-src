//sg
#include <stdio.h>
#include <stdlib.h>

int q, a; //the prime number and it's multiplicative inverse, known to all
int abmodn(int a, int b, int n) 
{
	int i = 0;
	int res = 1;
	for(i = 0; i < b; i++) {
		res = (res*a)% n;
	}
	return res % n;
}

int primitiveRoot(int p)
{
	int a = 2;
	int found = 1, i;
	int *checkerHash = malloc(sizeof(int) * (p));
	 
	while(1) {
		for(i = 1; i < p; i++) {
			checkerHash[i] = -1;
		}
		for(i = 1; i < p; i++) {
			checkerHash[abmodn(a, i, p)] = 1;
		}
		for(i = 1; i < p; i++) {
			if(checkerHash[i] == -1) {
				found = 0;
				break;
			}
		}
		if(found) {
			return a;
		}
		found = 1;
		a++;
	 }
}
int main()
{
	int XA, XB, YA, YB, ka, kb;
	printf("Enter the global prime q : ");
	scanf("%d", &q);
	a = primitiveRoot(q);
	srand(time(NULL));
	//the private keys
	XA = (rand() % (q - 1)) + 1;
	XB = (rand() % (q - 1)) + 1;
	//the public keys
	YA = abmodn(a, XA, q);
	YB = abmodn(a, XB, q);
	
	//calculation of keys
	ka = abmodn(YB, XA, q);
	kb = abmodn(YA, XB, q);
	printf("XA = %d\nXB = %d\nYA = %d\nYB = %d\nka = %d\nkb = %d\n", XA, XB, YA, YB, ka, kb);
		
	if(ka == kb) {
		printf("Diffie hellman executed correctly :\nka = kb = %d\n", ka, kb);
	} else {
		printf("There was some problem. Quitting quitely\n");
		return -1;
	}	
	return 0;
}
