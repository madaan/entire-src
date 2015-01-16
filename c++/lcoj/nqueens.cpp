//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
    typedef vector< string > BOARD;
    vector< BOARD > sols;
public:
    vector<vector<string> > solveNQueens(int n) {
        BOARD b(n, string(n, '.'));
        //cout << b.size() << " " << b[0].size() << "\n";
        nqueens(0, n, b);
        return sols;
    }
    void nqueens(int c, int n, BOARD b) {
        if(c >= n) {
            sols.push_back(BOARD(b));
            return;
        }
        for(int r = 0; r < n; r++) {
            if(ok(r, c, b, n)) {
                b[r][c] = 'Q';
                nqueens(c + 1, n, b);
                b[r][c] = '.';
            }
        }
    }
    bool ok(int r, int c, const BOARD &b, int n) {
        if(r >= n || c >= n || r < 0 || c < 0) {
            return false;
        }
        for(int i = 0; i < n; i++) {
            if(i != c && b[r][i] == 'Q') {
                return false;
            }
            if(i != r && b[i][c] == 'Q') {
                return false;
            }
        }
        for(int i = r + 1, j = c + 1; i < n && j < n; i++, j++) {
            if(b[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if(b[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--) {
            if(b[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if(b[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
void dump(vector<string> &b, int n) {
    for(int i = 0; i < b.size(); i++) {
        cout << b[i] << "\n";
    }
}
int main() {
    Solution s;
    int n = 25;
    vector< vector< string> > sols = s.solveNQueens(n);
    for(int i = 0; i < sols.size(); i++) {
        dump(sols[i], n);
        cout << "\n";
    }
    cout << sols.size() << "\n";
    return 0;
}
