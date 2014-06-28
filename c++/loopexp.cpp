//sg
#include<stdio.h>
typedef long long ll;
#define MAX 100009
double cache[MAX];

void makeCache() {
    double currSum = 2.5;

    for(int i = 3; i < MAX; i++) {
        cache[i] = (currSum + i) / i;
        currSum += cache[i];
    }
}

double expectedVal(int n) {
    if(n == 0) {
        return 0;
    }
    if(cache[n] != 0) {
        return cache[n];
    }
    double res = 0;
    for(int i = 1; i <= n; i++) {
        if(cache[n - i] == 0) {
            cache[n - i] = expectedVal(n - i);
        }
        res += (cache[n - i] + 1);
    }
    cache[n] = res / n;
    return cache[n];
}

int main() {
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 1.5;
    int t, n;
    scanf("%d", &t);
    makeCache();
    while(t--) {
        scanf("%d", &n);
        printf("%f\n", expectedVal(n));
    }
    return 0;
}



