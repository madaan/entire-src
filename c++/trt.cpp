//sg
#include<bits/stdc++.h>
#define MAX 2005
using namespace std;
int dp[MAX][MAX];
int age = 1;
int v[MAX];
int n;
int cost(int i, int j) {
    if(i == j) {
        //printf("cost(%d, %d) = %d (v[%d] = %d) at age = %d\n", i, j, age * v[i], i, v[i], age);
        return (i + n - j) * v[i];
    }
    if(i > j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i + 1][j] = cost(i + 1, j);
    dp[i][j - 1] =  cost(i, j - 1);
    dp[i][j] = max(v[i] *(i + n - j) + dp[i + 1][j],v[j] * (i + n - j) + dp[i][j - 1]);
    //printf("dp[%d][%d] = %d age = %d, v[%d] = %d i = %d, j = %d\n", i + 1, j, dp[i + 1][j], age, i, v[i], i, j);
    return dp[i][j];
}
int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%d\n", cost(0, n - 1));
    return 0;
}
