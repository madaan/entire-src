//sg
#include<bits/stdc++.h>
using namespace std;
#define MAXX 10009
#define MAX 108
#define INF 100000009
typedef long long ll;
ll dp[MAX][MAXX];
//wt[i] has weights for color i
vector< int > wt[MAX];
int n, m;
ll solve(int i, int x) {
    //cout << "solve(" << i << ", " << x << ")\n";
    if(dp[i][x] != -1) return dp[i][x];
    if(i == m) {
        return dp[i][x] = x;
    }
    if(x <= 0) {
        return dp[i][x] = INF;
    }
    ll ans = INF;
    for(int j = 0, l = wt[i + 1].size(); j < l; j++) {
        if(x - wt[i + 1][j] < 0) continue;
        ans = min(ans, solve(i + 1, x - wt[i + 1][j]));
    }
    return dp[i][x] = ans;
}

int main() {
    int  x, temp;
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> m >> x;
        vector< int > elems(n);
        vector< int > clr(n);
        for(int i = 0; i < n; i++) {
            cin >> elems[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> temp;
            wt[temp].push_back(elems[i]);
        }
        int res = solve(0, x);
        cout << ((res == INF) ? -1 : res) << "\n";
        for(int i = 0; i < MAX; i++) 
            wt[i].clear();

    }
    return 0;
}
