//sg
#include<bits/stdc++.h>
using namespace std;
#define M 17
#define P 121
#define MAX 1000009
int wt[P], cwt[P];
int dp[P][M];

//gives the ans 
int ans(int i, int p) {
    if(dp[i][p] != -1) return dp[i][p];
    if(p == 1) {
        return dp[i][p] = cwt[i];
    }
    int minOthers = MAX;
    for(int j = i - 1; j >= 1; j--) {
        minOthers = min(minOthers, max(ans(j, p - 1), cwt[i] - cwt[j]));
    }
    minOthers = min(minOthers, ans(i, p - 1));
    return dp[i][p] = minOthers;
}

int main() {
    int m, p;
    cin >> m >> p;
    memset(dp, -1, sizeof(dp));
    cwt[0] = 0;
    for(int i = 1; i <= p; i++) {
        cin >> wt[i];
        cwt[i] = wt[i] + cwt[i - 1];
    }
    cout << ans(p, m) << "\n";
    return 0;
}
