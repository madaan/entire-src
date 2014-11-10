//sg
#include<bits/stdc++.h>
using namespace std;
void genParens(int n, int lp, int rp, string res) {
    //cout << lp << " " << res << "\n";
    if(lp == n && rp == n) {
        cout << res << "\n";
    }

    if(lp < n) {
        res += '(';
        genParens(n, lp + 1, rp, res);
        res.pop_back();
    }
    if(lp > rp) {
        res += ')';
        genParens(n, lp, rp + 1, res);
        res.pop_back();
    }
}
int main() {
    string temp = "";
    genParens(30, 0, 0, temp);
    return 0;
}

