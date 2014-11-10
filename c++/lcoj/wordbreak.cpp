//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s;
    unordered_set<string> dict;
    int dp[10000];
    bool solve(int st) {
        if(dp[st] != -1) {
            return dp[st];
        }
        string cs = s.substr(st);
        if(dict.find(cs) != dict.end()) {
            return true;
        }
        bool res = false;
        for(int i = 0, l = cs.length(); i < l; i++) {
            if(dict.find(cs.substr(0, i)) != dict.end()) {
                res = res | solve(st + i);
            }
        }
        return dp[st] = res;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        memset(dp, -1, sizeof(dp));
        this->s = s;
        this->dict = dict;
        return solve(0);
    }
};
int main() {
    Solution s;
    ifstream i("t", ios::in);
    unordered_set<string> dict;
    string x;
    while(i >> x) {
        dict.insert(x);
    }
    i.close();
    cout << s.wordBreak("acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb", dict);
    return 0;
}

