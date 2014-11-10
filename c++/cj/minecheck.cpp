//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< string > CMAT;
typedef vector < vector< int > >  IMAT;
typedef vector< vector < bool > > BMAT;
int R, C;
void dump(CMAT x) {
    for(int i  = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << x[i][j] << " " ;
        }
        cout << "\n";
    }
}
int nbr(int i, int j, CMAT x) {
    int res = 0;
    static int moves[8][2] = {{-1,0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    for(int m = 0; m < 8; m++) {
        int ti = i + moves[m][0];
        int tj = j + moves[m][1];
        if(ti < 0 || tj < 0 || ti >= R || tj >= C) continue;
        if(x[ti][tj] == '*') {
            res++;
        }
    }
    return res;
}
IMAT genImat(CMAT x) {
    IMAT res(R, vector<int>(C, 0));
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            res[i][j] = nbr(i, j, x);
    return res;
}
//recursively opens all zeroes
bool open(int i, int j, IMAT sol, BMAT &opened) {
    static int moves[8][2] = {{-1,0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    opened[i][j] = true;
    for(int m = 0; m < 8; m++) {
        int ti = i + moves[m][0];
        int tj = j + moves[m][1];
        if(ti < 0 || tj < 0 || ti >= R || tj >= C) continue;
        if(sol[ti][tj] == 0 && !opened[ti][tj]) {
            open(ti, tj, sol, opened);
        }
        opened[ti][tj] = true;
    }
}
bool sat(BMAT b, CMAT x) {
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(!b[r][c] && x[r][c] != '*') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int t;
    int M;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        cin >> R;
        C = R;
        CMAT m(R, string(C, ' '));
        for(int i = 0; i < R; i++) {
            cin >> m[i];
        }
        IMAT sol = genImat(m);
        BMAT opened(R, vector< bool >(C, false));
        int res = 0;
        bool found = false;
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if(sol[r][c] == 0 && m[r][c] != '*' && !opened[r][c]) {
                    open(r, c, sol, opened);
                    res++;
                }
            }
        }
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(m[i][j] != '*' && !opened[i][j]) {
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
