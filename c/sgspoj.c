//sg
#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a < b) ? a : b)
int arr[110];

int cost(int l, int r)
{
    int sum = 0, i = 0;
    for(i = l; i <= r; i++) {
        sum += arr[i];
    }
    return sum % 100;
}

int mixtures(int n)
{
    int i, j, k;
    unsigned int smoke[110][110];
    for(i = 0; i < 100; i++) {
        for(j = 0; j < 100; j++) {
            smoke[i][j] = 1000000;
        }
    }
    for(i = 0; i < n - 1; i++) {
        smoke[i][i] = 0;
        smoke[i][i + 1] = (arr[i] * arr[i + 1]);
    }
    smoke[n - 1][n - 1] = 0;

    for(k = 3; k <= n; k++) { //length of various chains
        for(i = 0; i <= n - k; i++) { //left side
            for(j = i; j < i + k - 1; j++) { 
                //printf("Cost : %d\n", cost(i, j) * cost(j + 1, i + k -1));
                //printf("i = %d, j = %d, k = %d\n", i, j, k);
                //printf("a = %d, b = %d\n", smoke[i][i + k - 1], smoke[i][j] + smoke[j + 1][i + k - 1] + cost(i, j) * cost(j + 1, i + k -1));

                smoke[i][i + k - 1] = min(smoke[i][i + k - 1], smoke[i][j] + smoke[j + 1][i + k - 1] + cost(i, j) * cost(j + 1, i + k -1));
                
                //printf("min = %d\n", min(smoke[i][i + k - 1], smoke[i][j] + smoke[j + 1][i + k - 1] + cost(i, j) * cost(j + 1, i + k -1)));
            }
        }
    }
    /*
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%15d", smoke[i][j]);
        }
        printf("\n");
    }
    */
    return smoke[0][n - 1];
}

int main()
{
    int t, N, i;
    while(scanf("%d", &N) != EOF) {
        for(i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", mixtures(N));
    }
    return 0;

}
