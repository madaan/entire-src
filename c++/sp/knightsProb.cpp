//sg
#include<bits/stdc++.h>
using namespace std;
double dp[9][9][1000];
double val(int x, int y) {
    int knmoves[8][2] = {
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1}
    };
    double res = 0.0;
    for(int i = 0; i < 8; i++) {
        int dx = x + knmoves[i][0];
        int dy = y + knmoves[i][1];
        if(dx <= 0 || dy <= 0 || dx > 8 || dy > 8) {
            continue;
        }
        else {
            res += 1;
        }
    }
    return res / 8;

}
double prob(int x, int y, int n) {
    if(dp[x][y][n] != 0) {
        return dp[x][y][n];
    }
    if(n == 1) {
        return dp[x][y][n] = val(x, y);
    }
    int knmoves[8][2] = {
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1}
    };
    double res = 0.0;
    for(int i = 0; i < 8; i++) {
        int dx = x + knmoves[i][0];
        int dy = y + knmoves[i][1];
        if(dx <= 0 || dy <= 0 || dx > 8 || dy > 8) continue;
        res += 0.125 * prob(dx, dy, n - 1);
    }
    return dp[x][y][n] = res;
}


int main() {
    memset(dp, 0, sizeof(dp));
    cout << prob(4, 3, 50) << "\n";
    return 0;
}
