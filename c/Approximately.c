//sg
#include<stdio.h>
int main() {
	int fullRounds, remaining;
	int k ,T;
	char recurring[] = "415926530119026040722614947737296840070086399613316";
	char formatStr[100];
	scanf("%d",&T);
	while( T--) {
		scanf("%d", &k);
	if(k == 0 ) {
		printf("3\n");
	} else if(k == 1) {
		printf("3.1\n");
	} else {
		fullRounds = (k - 1)/51;
		remaining = (k - 1)%51;
		printf("3.1");
		while( fullRounds-- ) {
			printf("415926530119026040722614947737296840070086399613316");
		}
		sprintf(formatStr,"%%.%ds",remaining);
		printf(formatStr,recurring);
		printf("\n");
	}
}
	 printf("%s",digits);
	 return 0;
 }
	
