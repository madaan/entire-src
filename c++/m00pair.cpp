//sg
#include<vector>
#include<stdio.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
ll ones[1100], zeroes[1100], pairs[1100];
void preprocess() {
    ones[0] = 1;
    zeroes[0] = 0;
    pairs[0] = 0;
    ones[1] = 1;
    zeroes[1] = 1;
    pairs[1] = 0;
    ones[2] = 2;
    zeroes[2] = 2;
    pairs[2] = 1;
    for(int i = 3; i < 1000; i++) {
        ones[i] = ones[i - 1]  * 2;
        zeroes[i] = zeroes[i - 1] * 2;
        pairs[i] = pairs[i - 2] + ones[i - 3] + zeroes[i - 3];
        //printf("1s = %lld, 0s = %lld, pairs = %lld\n", ones[i], zeroes[i], pairs[i]);
    }
}
int main() {
    int n, res;
    preprocess();
    while((res = scanf("%d", &n) != EOF)) {
        printf("%lld\n", pairs[n]);
    }
    return 0;
}
