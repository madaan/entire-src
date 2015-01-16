//sg
#include <stdio.h>
int main()
{
    int t;
    double pA;
    int M = 10000;
    float RA;
    double E, max, ct1, ct2;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf", &pA);
        max = 0;
        ct1 = 2*pA - 1;
        ct2 = M*pA;
        for(int i = 0; i < 10001; i += 10) {
            E = ct1 * (i - ct2);
            if(E > max) {
                max = E;
            }
        }
        printf("%lf\n", M + max);
    }
    return 0;
}
