//sg
#include<bits/stdc++.h>
using namespace std;
int solve(string s) {
    int l = s.length();
    vector< vector<bool> > dp(l + 1, vector<bool>(l + 1, false));
    for(int i = 0; i < l - 1; i++) {
        dp[i][i] = true;
        dp[i][i + 1] = s[i] == s[i + 1];
    }
    dp[l - 1][l - 1] = true;
    for(int k = 3; k <= l; k++) {
        for(int j = 0; j < l - k + 1; j++) {
            int b = j + k - 1;
            dp[j][b] = (s[j] == s[b]) && (dp[j + 1][b -1]);
        }
    }
    set<string> palis;
    for(int i = 0; i < l; i++) {
        for(int j = i; j < l; j++) {
            if(dp[i][j]) {
                palis.insert(s.substr(i, j - i + 1));
            }
        }
    }
    return palis.size();
}

int main() {
    string s("aabaa");
    cout << solve(s) << "\n";
    return 0;
}
