//sg
#include <stdio.h>
#include <math.h>
bool isPrime(long long a)
{
    long long b = sqrt(a); // only need to test up to the square root of the input
    for (long long i = 2; i <= b; i++)
    {
        if (a % i == 0)
            return false;
    }
    // if the loop completed, a is prime
    return true;
}
bool mikeWins(long long N) {
    //mike wins only if the following conditions are not there
    if(N == 1 || N == 3 || N == 5) {
        return false;
    }
    if(isPrime(N)) {
        N--;
        if(N % 3 == 0 || N % 5 == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    long long N;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%lld", &N);
        if(mikeWins(N)) {
            printf("Mike\n");
        } else {
            printf("Tom\n");
        }
    }
    return 0;
}
