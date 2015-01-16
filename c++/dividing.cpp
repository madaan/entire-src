//sg
#include<stdio.h>
int main()
{
    long long int N, sum = 0, expected, n;
    scanf("%lld", &N);
    expected = (N * (N + 1)) / 2;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &n);
        sum += n;
    }
    if(sum == expected) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
