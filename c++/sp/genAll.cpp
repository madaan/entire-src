//sg
#include<bits/stdc++.h>
using namespace std;

vector<string> gen(int l, int pos, string charSet) {

    vector<string> vec;
    if(pos == l - 1) {
        for(int i = 0, csl = charSet.length(); i < csl; i++) {
            vec.push_back(string(1, charSet[i]));
        }
        return vec;
    }
    int csl = charSet.length();
    vector<string> lowerCardStrs = gen(l, pos + 1, charSet);
    for(int i = 0; i < csl; i++) {
        for(int str = 0, lcsl = lowerCardStrs.size(); str < lcsl; str++) {
            string temp(1, charSet.c_str()[i]);
            vec.push_back(temp + lowerCardStrs[str]);
        }
    }
    return vec;
}

void solve(int l, int k, string charSet) {
    vector<string> res = gen(l, k, charSet);
    for(int i = 0, rl = res.size(); i < rl; i++) {
        cout << res[i] << "\n";
    }
}

int main() {
    string charset("abc");
    solve(7, 0, charset);
    return 0;
}

