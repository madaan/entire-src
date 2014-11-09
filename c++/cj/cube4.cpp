//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
int maze[MAX][MAX];
int dp[MAX][MAX];
int from[MAX][MAX];
int s;


int solve(int dp[][MAX], int r, int c) {
    if(dp[r][c] != 0) {
        return dp[r][c];
    }
    dp[r][c] += 1;
    int moves[4][2] = {{1,0}, {0,1}, {0, -1}, {-1, 0}};
    for(int m = 0; m < 4; m++) {
        int di = r + moves[m][0];
        int dj = c + moves[m][1];
        if((maze[r][c] - maze[di][dj]) != -1) {
            continue;
        }
        if(di < 0 || dj < 0 || di >= s || dj >= s) {
            continue;
        }
        dp[r][c] = max(dp[r][c], solve(dp, di, dj) + 1);
    }
    return dp[r][c];
}

int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        cin >> s;
        printf("Case #%d: ", tt);
        for(int i = 0; i < s; i++) {
            for(int j = 0; j < s; j++) {
                cin >> maze[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        //for all the numbers, fill dp

        for(int i = 0; i < s; i++) {
            for(int j = 0; j < s; j++) {
                if(dp[i][j] == 0) solve(dp, i, j);
            }
        }
        int res = 0;
        int maxi = 0;
        int maxj = 0;
        int lm;
        for(int i = 0; i < s; i++) {
            for(int j = 0; j < s; j++) {
                //cout << " " << dp[i][j];
                if(((dp[i][j] == res) && maze[i][j] < lm) || (dp[i][j] > res)){
                    res = dp[i][j];
                    maxi = i;
                    maxj = j;
                    lm = maze[maxi][maxj];
                }
            }
        }
        //now get the base
        /*
        bool moving = true;
        while(moving) {
            moving = false;
            int moves[4][2] = {{1,0}, {0,1}, {0, -1}, {-1, 0}};
            for(int m = 0; m < 4; m++) {
                int di = maxi + moves[m][0];
                int dj = maxj + moves[m][1];
                int ni, nj;
                if(di < 0 || dj < 0 || di >= s || dj >= s) {
                    continue;
                }
                if(dp[maxi][maxj] - dp[di][dj] == 1) {
                    maxi = di;
                    maxj = dj;
                    moving = true;
                    break;
                }
            }
        }
        */

        cout << maze[maxi][maxj] << " " << res<< "\n";
    }
    return 0;
}






