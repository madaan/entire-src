//sg
#include <stdio.h>
int main()
{
    long long sum, c, N, t, i;
    scanf("%lld", &t);
    while(t--) { 
        sum = 0;
        scanf("%lld", &N);
        if(N == 0) { 
            printf("NO\n");
            continue;
        }
        for(i = 0; i < N; i++) {
            scanf("%lld", &c);
            sum = sum + c;
            sum = sum % N;
        }
        if(sum % N == 0) { 
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;

}
