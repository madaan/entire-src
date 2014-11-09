//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkRow(vector<char> &r) {
        vector< bool > rowMap(10, false);
        for(int i = 0; i < 9; i++) {
            if(r[i] != '.')
            rowMap[r[i] - 48] = true; 
        }
        for(int i = 1; i < 10; i++) {
            if(!rowMap[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkCol(vector< vector<char> > &b, int cn) {
        vector< bool > colMap(10, false);
        for(int i = 0; i < 9; i++) {
            if(b[i][cn - 48] != '.')
            colMap[b[i][cn] - 48] = true;
        }
        for(int i = 1; i < 10; i++) {
            if(!colMap[i]) {
                return false;
            }
        }
        return true;
    }

    bool subCheck(vector< vector< char> > &b) {
        for(int roff = 0; roff < 9; roff += 3) {
            for(int coff = 0; coff < 9; coff += 3) {
                vector< bool > subMap(10, false);
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(b[i + roff][j + coff] != '.') 
                        subMap[b[i + roff][j + coff] - 48] = true;
                    }
                }
                for(int i = 1; i < 10; i++) {
                    if(!subMap[i]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }




    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++) {
            if(!checkRow(board[i]) || !checkCol(board, i)) {
                return false;
            }
        }
        return subCheck(board);
    }

    void getNxt(vector<vector<char> > &board, int &r, int &c) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    r = i;
                    c = j;
                    return;
                }
            }
        }
        r = -1;
    }

    void dump(vector< vector < char > > board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void solve(vector< vector < char > > board, vector< vector < char >  > &res, bool found) {
        if(found) {
            return;
        }
        int r, c;
        getNxt(board, r, c);
        if(r == -1) {
            if(isValidSudoku(board)) {
                res = vector<vector< char > > (board);
                found = true;
            }
            return;
        }
        vector< bool > used(10, false);
        for(int i = 0; i < 9; i++) {
            if(board[r][i] != '.') {
                used[board[r][i] - 48] = true;
            }
            if(board[i][c] != '.') {
                used[board[i][c] - 48] = true;
            }
            int roff = (r / 3) * 3;
            int coff = (c / 3) * 3;
            for(int rr = 0; rr < 3; rr++) {
                for(int cc = 0; cc < 3; cc++) {
                    if(board[roff + rr][coff + cc] != '.')
                    used[board[roff + rr][coff + cc] - 48] = true;
                }
            }

        }
        for(int i = 1; i <= 9; i++) {
            if(used[i]) continue;
            board[r][c] = char(i + 48);
            solve(board, res, found);
            if(found) return;
        }
    }


    void solveSudoku(vector<vector<char> > &board) {
        int bh = board.size();
        int bw = board[0].size();
        vector< vector < char > > res;
        int found = false;
        solve(board, res, found);
        for(int i = 0; i < bh; i++) {
            for(int j = 0; j < bw; j++) {
                board[i][j] = res[i][j];
            }
        }
    }


};

int main() {
    char const *str[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    //char const *str[] = {"519748632","783652419","426139875","357986241","264317598","198524367","975863124","832491756","641275983"};
    vector< vector < char > > board(9, vector<char>(9, '.'));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            board[i][j] = str[i][j];
        }
    }
    Solution s;
    s.solveSudoku(board);
    s.dump(board);
    //cout << s.isValidSudoku(board);
    return 0;
}
