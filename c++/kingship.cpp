//sg
#include <stdio.h>
#include <algorithm>
#define max(a, b) (a > b ? a : b)
int main()
{
    int T, P[100010], N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        int s = 10000000, in = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d", &P[i]);
            if(P[i] < s) {
                s = P[i];
                in = i;
            }
        }
        //std::sort(P, P + N);
        long long int cost = 0, first = s, temp;
        for(int i = 0; i < in; i++) {
            temp = first * P[i];
            cost += temp;
        }
        for(int i = in + 1; i < N; i++) {
            temp = first * P[i];
            cost += temp;
        }
        printf("%lld\n", cost);
    }
    return 0;
 
}
