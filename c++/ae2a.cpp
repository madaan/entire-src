//sg
#include<stdio.h>
#include<string.h>
#define MAXN 1010
#define MAXK 6060
#define UNDEF 1.0
typedef long long ll;
double cache[MAXN][MAXK];
double f(int n, int k) {
    //printf("f(%d, %d)\n", n, k);
    if(n > 1000) {
        return 0;
    }
    if(k > n * 6) {
        return 0;
    }
    if(k <= 0) {
        return 0;
    }
    if(cache[n][k] != UNDEF) {
        return cache[n][k];
    }
    double temp = 0;
    for(int i = 1; i <= 6; i++) {
        if(k - i <= 0) {
            break;
        }
        if(cache[n - 1][k - i] == UNDEF) {
            cache[n - 1][k - i] = f(n - 1, k - i);
        }
        //printf("cache[%d][%d] = %f\n", n - 1, k - i, cache[n - 1][k - i]);
        temp += cache[n - 1][k - i];
    }
    cache[n][k] = (temp / 6);
    return cache[n][k];
}
int main() {
    int t, n, k;
    scanf("%d", &t);
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXK; j++) {
            cache[i][j] = UNDEF;
        }
    }
    //memset(cache, UNDEF, sizeof(cache[0][0]) * MAXN * MAXK);
    for(int i = 1; i <= 6; i++) {
        cache[1][i] = (1.0 / 6.0);
    }
    while(t--) {
        scanf("%d%d", &n, &k);
        int res = (f(n, k) * 100);
        printf("%d\n", res);
    }
    return 0;
}
