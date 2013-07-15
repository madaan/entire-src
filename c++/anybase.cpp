//sg
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPali(long long *arr, int n)
{
    int i = 0;
    for(i = 0; i < n/2; i++) {
        if(arr[i] != arr[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

long long res[100];
void decToBase(long long n, long long b, int *l) 
{
    long long i = 0;
    while(n) {
        res[i++] = n % b;
        n /= b;
    }
    *l = i;
}
int main(int agc, char *av[])
{
    long long N;
    int T;
    scanf("%d", &T);
    long long ar[] = {12, 11, 10, 11, 12};
   // if(checkPali(decToBase(N, i), i)) {
    int l;
    while(T--) {
        scanf("%lld", &N);
        if(N == 1 || N == 3 || N == 5) {
            printf("2\n");
            continue;
        }

        for(long long i = 2; i < N; i++) {
            decToBase(N, i, &l);
            if(checkPali(res, l)) {
                printf("%lld\n", i);
                break;
            }
        }
    }
   return 0;
} 
