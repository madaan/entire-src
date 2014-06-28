//sg
#include<stdio.h>
typedef long long ll;

int main() {
    int t;
    ll n;
    long double num1, num2, den1, den2;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);
        long double res;
        if(n % 2 != 0) {
            num1 = n + 3;
            num2 = n + 3;
            den1 = 8;
            den2 = 6;
        } else {
            num1 = n;
            num2 = n;
            den1 = 8;
            den2 = 6;
        }
        res = num2 / den2;
        //printf("res = %f\n", res);
        res = res * (num1 / den1);
        //printf("res = %f\n", res);
        ll resInt = res;
        double diff = res - resInt;
        if(diff > 0.5) {
            printf("%lld\n", resInt + 1);
        } else {
            printf("%lld\n", resInt);
        }
    }
    return 0;
}
