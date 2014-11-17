//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int, int> pi;
    typedef pair<int, pi> ppi;
    int rows, cols, l;
    bool found(vector<vector < char > > &board, int r, int c, string word, int fl, vector< vector< bool > > &visited) {
        /*
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << visited[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        */
        int moves[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        bool res = false;
        for(int i = 0; i < 4; i++) {
            int pos = fl; //index matched till parent
            if(pos == l - 1) {
                return true;
            }
            int di = r + moves[i][0];
            int dj = c + moves[i][1];
            visited[r][c] = true;
            if(di < 0 || dj < 0 || di >= rows || dj >= cols || visited[di][dj]) {
                continue;
            }
            if(board[di][dj] == word[pos + 1]) {
                pos++; //have matched till pos
                //cout << "At " << r << " " << c << " -> " << word[fl] << "\n";
                //cout << "    " << "nbr : " << di << " " << dj << "\n";
                res = res | found(board, di, dj, word, pos, visited);
            }
        }
        visited[r][c] = false;
        return res;
    }

    bool exist(vector<vector<char> > &board, string word) {
        rows = board.size();
        cols = board[0].size();
        l = word.length();
        vector< vector < bool > > visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0]) {
                    if(found(board, i, j, word, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    char const * words [] = {"ABCE", "SFES", "ADEE"};
    vector< vector < char > > c2;
    c2.push_back(vector<char>(words[0], words[0] + 4));
    c2.push_back(vector<char>(words[1], words[1] + 4));
    c2.push_back(vector<char>(words[2], words[2] + 4));
    vector< vector < char > > c(1, vector<char>(2, 'a'));
    Solution s;
    cout << s.exist(c2, string("ABCESEEEFS")) << "\n";
    return 0;
}
