//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int minCut(string s) {
        int sl = s.length();
        vector<int> dp(sl + 1, 100000000);
        vector< vector<bool> > pali(sl + 1, vector<bool> (sl + 1, false));
        dp[sl] = 0;
        for(int i = 0; i < sl; i++) {
            pali[i][i] = true;
        }
        for(int i = 0; i < sl - 1; i++) {
            pali[i][i + 1] = (s[i] == s[i + 1]);
        }
        for(int k = 3; k <= sl; k++) {
            for(int j = 0; j < sl - k + 1; j++) {
                pali[j][j + k - 1] = (s[j] == s[j + k - 1]) && (pali[j + 1][j + k - 2]);
            }
        }
        for(int i = sl - 1; i >= 0; i--) {
            for(int j = i + 1; j <= sl; j++) {
                //get the string [i, j)
                if(pali[i][j - 1]) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp[0] - 1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.minCut(argv[1]) << "\n";
    return 0;
}
