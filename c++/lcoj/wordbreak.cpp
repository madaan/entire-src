//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s;
    unordered_set<string> dict;
    int dp[10000];
    vector<int> validIndexes;
    vector<string> sols;
    int sl;
    bool solve(int st) {
        if(dp[st] != -1) {
            return dp[st];
        }
        string cs = s.substr(st);
        if(dict.find(cs) != dict.end() && (st + ) {

            //at this point, all the cuttings are a solution
            string res = "";
            int prev = 0;
            cout << validIndexes.size() << "\n";
            for(int i = 0, l = validIndexes.size(); i < l; i++) {
                res += s.substr(prev, validIndexes[i] - prev) + " ";
                prev = validIndexes[i];
            }
            res += s.substr(prev);
            sols.push_back(res);
            return true;
        }
        bool res = false;
        for(int i = 0, l = cs.length(); i < l; i++) {
            if(dict.find(cs.substr(0, i)) != dict.end()) {
                validIndexes.push_back(st + i);
                res = res | solve(st + i);
                validIndexes.pop_back();
            }
        }
        return dp[st] = res;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        memset(dp, -1, sizeof(dp));
        this->s = s;
        this->dict = dict;
        solve(0);
        return sols;
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
    vector<string> sols = s.wordBreak(string("aa"), dict);
    for(string str : sols) {
        cout << str << "\n";
    }
    return 0;
}
