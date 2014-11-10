//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< string > CMAT;
typedef vector < vector< int > >  IMAT;
typedef vector< vector < bool > > BMAT;
int R, C;
vector<CMAT> possibsols;
void gensols(int i, int j, int mines, CMAT m) {
    if(mines < 0) return;
    //cout << i << ", " << j << "\n";
    if(i == R) { //at the last element?
        if(mines == 0) {
            possibsols.push_back(CMAT(m));
        }
        return;
    }
    int nr, nc;
    nr = i;
    nc = j + 1;
    if(nc == C) {
        nr += 1;
        nc = 0;
    }
    m[i][j] = '*';
    gensols(nr, nc, mines - 1, m);
    m[i][j] = '.';
    gensols(nr, nc, mines, m);
}
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
bool check(int i, int j, IMAT sol, BMAT &opened) {
    static int moves[8][2] = {{-1,0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    opened[i][j] = true;
    for(int m = 0; m < 8; m++) {
        int ti = i + moves[m][0];
        int tj = j + moves[m][1];
        if(ti < 0 || tj < 0 || ti >= R || tj >= C) continue;
        if(sol[ti][tj] == 0 && !opened[ti][tj]) {
            check(ti, tj, sol, opened);
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
        possibsols.clear();
        cout << "Case #" << i << ":\n";
        cin >> R >> C >> M;
        int mines = M;
        CMAT m(R, string(C, '.'));
        gensols(0, 0, M, m);
        for(int i = 0, l = possibsols.size(); i < l; i++) {
            bool found = false;
            IMAT sol = genImat(possibsols[i]);
            for(int r = 0; r < R; r++) {
                for(int c = 0; c < C; c++) {
                    if(sol[r][c] == 0) {
                        BMAT opened(R, vector< bool >(C, false));
                        check(r, c, sol, opened);
                        if(sat(opened, possibsols[i])) {
                            possibsols[i][r][c] = 'c';
                            dump(possibsols[i]);
                            found = true;
                        }
                    }
                    if(found) {
                        break;
                    }
                }
                if(found) {
                    break;
                }
            }
            if(found) {
                break;
            }
        }
    }
    return 0;
}
