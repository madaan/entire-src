//sg
#include <stdio.h>
int main()
{
    int N, a[1000][1000], i, j, ans_not_reduced, ans_reduced, out, in;
    int case_number = 1;
    while(1) {
        scanf("%d", &N);
        if(N == 0) {
            break;
        }
        ans_not_reduced = ans_reduced = 0;
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                scanf("%d", &a[i][j]);
                ans_not_reduced += a[i][j];
            }
        }
        for(i = 0; i < N; i++) {
            out = in = 0;
            for(j = 0; j < N; j++) {
                out += a[i][j];
                in += a[j][i];
            }
            if(out > in) {
                ans_reduced += (out - in);
            }
        }
        printf("%d. %d %d\n", case_number++, ans_not_reduced, ans_reduced);
    }
    return 0;
}
