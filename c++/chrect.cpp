//sg
#include <stdio.h>
#include <math.h>
int main()
{
    int T, N, M, K;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &N, &M, &K);
        if(N == 1) {
            if(M <= 2) {
                printf("0\n");
            } else {
                printf("%d\n", K);
            }
        } else if(M == 1) {
            if(N <= 2) {
                printf("0\n");
            } else {
                printf("%d\n", K);
            }
        } else {
            if(K <= 2) {
                printf("1\n");
            } else {
                printf("%d\n", (K + 1)/2);
            }
        }
    }
    return 0;
}
