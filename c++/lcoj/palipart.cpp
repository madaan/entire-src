//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPali(string s) {
        return s == string(s.rbegin(), s.rend());
    }
    vector< string > explode(string s, char c) {
        stringstream ss(s);
        vector<string> res;
        string temp;
        while(getline(ss, temp, c)) {
            res.push_back(temp);
        }
        return res;
    }

    vector< vector<string> > wordBreak(string s) {
        vector<string> res;
        int sl = s.length();
        unordered_map<int, vector<string> > locSuffixMap;
        locSuffixMap[s.length()].push_back("");
        for(int i = s.length() - 1; i >= 0; i--) {
            for(int j = i + 1; j <= sl; j++) {
                if(isPali(s.substr(i, j - i))) {
                    string sbstr = s.substr(i, j - i);
                    for(string str : locSuffixMap[j]) {
                        if(str == "") {
                            locSuffixMap[i].push_back(sbstr);
                        }
                        else
                        locSuffixMap[i].push_back(sbstr + " " + str);
                    }
                }
            }
        }
        vector < vector < string > > ans;
        for(string s : locSuffixMap[0]) {
            ans.push_back(explode(s, ' '));
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector< vector<string> > sols = s.wordBreak(string("abcd"));
    for(vector<string> str : sols) {
        for(string xx : str) {
            cout << xx << "\n";
        }
    }
    return 0;
}
