//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector< vector< int > > dp;
    int m, n;
    vector<vector<int> > obstacleGrid;
    int lastColFree, lastRowFree;
    int ans(int i, int j) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i >= m || j >= n) {
            return 0;
        }
        if(i == m - 1) {
            return dp[i][j] = lastRowFree;
        }
        if(j == n - 1) { 
            return dp[i][j] = lastColFree;
        }
        int ways = 0;
        if(obstacleGrid[i + 1][j] == 0) {
            ways += ans(i + 1, j);
        }
        if(obstacleGrid[i][j + 1] == 0) {
            ways += ans(i, j + 1);
        }
        return dp[i][j]= ways;
    }
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        this->obstacleGrid = obstacleGrid;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(m == 0) {
            return 0;
        }
        /*
        if(m == 1 || n == 1) {
            return 1;
        }
        */
        lastColFree = lastRowFree = 1;
        for(int j = 0; j < n; j++) {
            if(obstacleGrid[m - 1][j] == 1) {
                lastRowFree = 0;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][n - 1] == 1) {
                lastColFree = 0;
                break;
            }
        }
        dp = vector< vector<int> > (m + 1, vector<int>(n + 1, -1));
        return ans(0, 0);
    }
};
int main() {
    int arr[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<int> a(arr[0], arr[0] + 3);
    vector<int> b(arr[1], arr[1] + 3);
    vector<int> c(arr[2], arr[2] + 3);
    vector< vector<int> > op;
    op.push_back(a);
    op.push_back(b);
    op.push_back(c);
    Solution s;
    vector< vector<int > > op2(1, vector<int>(1, 0));
    cout << s.uniquePathsWithObstacles(op2) << "\n";
    return 0;
}
