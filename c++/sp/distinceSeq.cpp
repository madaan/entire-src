//sg
#include<bits/stdc++.h>
using namespace std;
int solve(string s) {
    int l = s.length();
    set<string> res;
    for(int k = 1; k <= l; k++) { //all substrings of length k
        for(int j = 0; j < l - k + 1; j++) {
            res.insert(s.substr(j, k));
        }
    }
    return res.size();
}

int main() {
    string s("aaab");
    cout << solve(s) << "\n";
    return 0;
}
