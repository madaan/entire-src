//sg
//The number of odd numbers in the Nth row of the pascal's triangle is 
//2^(number of ones) in binary representation of N
#include<stdio.h>
typedef unsigned long long ll;
int numOnes(ll N) {
    int numOnes = 0;
    ll ONE = 1;
    while(N) {
        if(N & ONE) {
            numOnes++;
        }
        N = N >> 1;
    }
    return 1 << numOnes;
}

int main() {
    int t;
    ll N;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &N);
        ll odd = numOnes(N);
        ll even = N - odd + 1;
        printf("%lld %lld\n", even, odd);
    }
    return 0;
}
