//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int sl = s.length();
        vector<int> dp(sl + 1, 0);
        for(int i = 0; i < sl; i++) {
            if(s[i] == '(') {
                dp[i] = 0;
            } else {
                if(i - 1 >= 0 && s[i - 1] == '(') {
                    dp[i] = ((i - 2 >= 0) ? dp[i - 2] : 0) + 2;
                } else if(i - 1 >= 0 && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
        }
        return *(max_element(dp.begin(), dp.end()));
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("(()())") << "\n";
    return 0;
}
