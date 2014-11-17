//sg
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int a, b, k, i, j, res, T;
    int N = 100000;
    int prime[100090];
    int facs[100090];
    //
    //generate all the prime numbers till 100000
    for(i = 0; i <= N; i++) {
        facs[i] = 0;
        prime[i] = 1;
    }
    facs[0] = facs[1] = 0;
    prime[1] = prime[0] = 0;
    for(i = 2; i * i <= N; i++) {
        if(prime[i] == 1) {
            for(j = i * i; j <= N; j += i) {
                prime[j] = 0;
            }
        }
    }
    for(i = 2; i <= N; i++) {
        if(prime[i] == 1) {
            for(int j = i; j <= N; j += i) {
                facs[j]++;
            }
        }
    }
    //prime generation done
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &a, &b, &k);
        res = 0;
        for(i = a; i <= b; i++) {
            if(facs[i] == k) {
                res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
