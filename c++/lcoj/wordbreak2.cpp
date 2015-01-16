//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        int sl = s.length();
        unordered_map<int, vector<string> > locSuffixMap;
        locSuffixMap[s.length()].push_back("");
        for(int i = s.length() - 1; i >= 0; i--) {
            for(int j = i + 1; j <= sl; j++) {
                if(dict.find(s.substr(i, j - i)) != dict.end()) {
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
        return locSuffixMap[0];
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
    vector<string> sols = s.wordBreak(string("abcd"), dict);
    for(string str : sols) {
        cout << str << "\n";
    }
    return 0;
}
