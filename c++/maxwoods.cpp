//sg
#include<bits/stdc++.h>
using namespace std;
int m, n;
#define MAX 250
int dp[MAX][MAX];
char val[MAX][MAX];
int solve(int r, int c) {
    if(dp[r][c] != -1) {
        return dp[r][c];
    }
    if(r < 1 || r > m || c < 1 || c > n) {
        return dp[r][c] = 0;
    }
    if(val[r][c] == '#') {
        return dp[r][c] = 0;
    }
    int currval = (val[r][c] == 'T' ? 1 : 0);
    if(r % 2 != 0) { //can only face right
        int fromLeft =  solve(r, c + 1);
        int fromTop =  solve(r + 1, c);
        if(fromLeft == -1 && fromTop == -1) dp[r][c] = currval;
        else dp[r][c] = currval + max(fromTop, fromLeft);
    } else {
        int fromRight =  solve(r, c - 1);
        int fromTop =  solve(r + 1, c);
        if(fromRight == -1 && fromTop == -1) dp[r][c] = currval;
        else dp[r][c] = currval + max(fromTop, fromRight);
    }
    return dp[r][c];
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= m; i++) {
            scanf("%s", val[i] + 1);
        }
        int res = 0;
        solve(1, 1);
        cout << dp[1][1] << "\n";
    }
    return 0;
}
