//sg
#include <stdio.h>
#include <stdlib.h>
typedef long long LL;
int main(int argc, char *argv[])
{
    if(argc != 2) { 
        printf("Usage : ./se N\n");
        return 0;
    }
    LL N = atoi(argv[1]);
    int *prime = malloc( sizeof(int) * (N + 1));
    LL *primesTilli = malloc(sizeof(LL) * (N + 1));
    LL i, j , ib;
    for(i = 0; i <= N; i++) {
            prime[i] = 1;
        }
    prime[1] = prime[0] = 0;
    for(i = 2; i * i <= N; i++) {
        if(prime[i] == 1) {
            for(j = i * i; j <= N; j += i) {
                prime[j] = 0;
            }
        }
    } 

    for(i = 0; i <= N; i++) {
        if(prime[i] == 1) {
            printf("%lld ", i);
        }
    }

    
    printf("\n");
    return 0;
}




