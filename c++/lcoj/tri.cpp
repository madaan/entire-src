//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector< vector< int > > dp, triangle;
    int rows;
    int solve(int row, int ele) {
        if(dp[row][ele] != -1) {
            return dp[row][ele];
        }
        if(row == rows - 1) {
            return dp[row][ele] = triangle[row][ele];
        }
        int ans = triangle[row][ele] + min(solve(row + 1, ele), solve(row + 1, ele + 1));
        return dp[row][ele] = ans;
    }


    int minimumTotal(vector<vector<int> > &triangle) {
        rows = triangle.size();
        this->triangle = triangle;
        dp = vector < vector < int > > (rows, vector<int> (rows, -1));
        return solve(0, 0);
    }
};

int main() {
    return 0;
}
