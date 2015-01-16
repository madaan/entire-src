//sg
#include <stdio.h>
typedef unsigned int LL;
LL fibo[1000000], res[1000000];
int bitCount(unsigned int u)
{
    unsigned int uCount;
    uCount = u
             - ((u >> 1) & 033333333333)
             - ((u >> 2) & 011111111111);
    return
        ((uCount + (uCount >> 3))
         & 030707070707) % 63;
}
void createFibo()
{
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 2;
    for(int i = 3; i < 1000000; i++) {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000007;
    }
}
int main()
{
    createFibo();
    int N, G, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &N, &G);
        if(bitCount(fibo[N]) == G) {
            printf("CORRECT\n");
        } else {
            printf("INCORRECT\n");
        }
    }
    return 0;
}
