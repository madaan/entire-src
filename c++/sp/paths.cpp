//sg
#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int m, n;
vector<string> grid;
#define INF 10000000
int solve(int i, int j) {
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(i == m - 1 && j == n - 1) {
        return dp[i][j] = 0;
    }
    int moves[3][2] = {{1, 1}, {1, 0}, {0, 1}};
    for(int mv = 0; mv < 3; mv++) {
        int di = i + moves[mv][0];
        int dj = j + moves[mv][1];
        if(di >= m || dj >= n  || grid[di][dj] == '0') continue;
        int tmp = solve(di, dj);
        if(tmp == INF) {
            continue;
        }
        if(dp[i][j] == -1) {
            dp[i][j] = tmp;
        }
        else {
            dp[i][j] = min(dp[i][j], tmp);
        }
    }
    if(dp[i][j] == -1) {
        return INF;
    }
    dp[i][j]++;

    return dp[i][j];
}

int main() {
    cin >> m >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        grid.push_back(tmp);
    }
    cout << solve(0, 0) << "\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
