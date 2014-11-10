//sg
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, k, T;
    int w[100];
    int sum = 0, sum1 = 0, temp, i , ls, rs, ls1, rs1;
    scanf("%d", &T);
    while(T--) {
        ls = rs = ls1 = rs1 = 0;
        sum = sum1 = 0;
        scanf("%d%d", &N, &k);
        int j = 0;
        for(j = 0; j < N; j++) {
            scanf("%d", &w[j]);
        }
        sort(w, w + N);
        //get the max k elements
        for(i = 0; i < k; i++) {
            ls += w[i];
        }
        for(i = k; i < N; i++) {
            rs += w[i];
        }
        for(i = 0; i < N - k; i++) {
            ls1 += w[i];
        }
        for(i = N - k; i < N; i++) {
            rs1 += w[i];
        }
//    printf("rs= %d, ls = %d\n", rs, ls);

        if(ls > rs) {
            sum = ls - rs;
        } else {
            sum = rs - ls;
        }
        if(ls1 > rs1) {
            sum1 = ls1 - rs1;
        } else {
            sum1 = rs1 - ls1;
        }
        printf("%d\n", (sum > sum1) ? sum : sum1);
    }
    return 0;
}
