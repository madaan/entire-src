//sg
//sg
#include<bits/stdc++.h>
using namespace std;
#define R 8
#define C 8
typedef vector< string > BOARD;
void addBoard(BOARD &b, char posc, char posn, char t) {
    int c = 7 - (posc - 65);
    int r = posn - 48 - 1;
    //cout << "\n" << r << " " << c << "\n";
    b[posn - 48 - 1][c] = t;

}
int pcldu(BOARD b, int r, int c) {
    r--;
    c--;
    while(r >= 0 && c >= 0) {
        if(b[r][c] != '.') {
            return 1;
        }
        r--;
        c--;
    }
    return 0;
}
int pcldd(BOARD b, int r, int c) {
    r++;
    c--;
    while(r < R && c >= 0) {
        if(b[r][c] != '.') {
            return 1;
        }
        r++;
        c--;
    }
    return 0;
}
int pcru(BOARD b, int r, int c) {
    r--;
    c++;
    while(r >= 0 && c <C) {
        if(b[r][c] != '.') {
            return 1;
        }
        r--;
        c++;
    }
    return 0;
}
int pcrd(BOARD b, int r, int c) {
    r++;
    c++;
    while(r < R && c < C) {
        if(b[r][c] != '.') {
            return 1;
        }
        r++;
        c++;
    }
    return 0;
}
int pc_down(BOARD b, int r, int c) {
    r++;
    while(r < R && c < C) {
        if(b[r][c] != '.') {
            return 1;
        }
        r++;
    }
    return 0;
}
int pc_up(BOARD b, int r, int c) {
    r--;
    while(r >= 0&& c < C) {
        if(b[r][c] != '.') {
            return 1;
        }
        r--;
    }
    return 0;
}
int pc_right(BOARD b, int r, int c) {
    c++;
    while(r < R && c < C) {
        if(b[r][c] != '.') {
            return 1;
        }
        c++;
    }
    return 0;
}
int pc_left(BOARD b, int r, int c) {
    c--;
    while(r < R && c >= 0) {
        if(b[r][c] != '.') {
            return 1;
        }
        c--;
    }
    return 0;
}
int getp(BOARD b, int i, int j) {
    int ans = 0;
    if(i + 1 < R && j - 1 >= 0 && b[i + 1][j - 1] != '.') {
        ans += 1;
    }
    if(i - 1 >= 0 && j - 1 >= 0 && b[i - 1][j - 1] != '.') {
        ans += 1;
    }
    return ans;
}
int getk(BOARD b, int i, int j) {
    static int moves[8][2] = {{-1,0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    int ans = 0;
    for(int m = 0; m < 8; m++) {
        int ti = i + moves[m][0];
        int tj = j + moves[m][1];
        if(ti < 0 || tj < 0 || ti >= R || tj >= C) continue;
        if(b[ti][tj] != '.') {
            ans++;
        }
    }
    return ans;
}
int getq(BOARD b, int i, int j) {
    return pcldu(b, i, j) + pcldd(b, i, j) + pcru(b, i, j) + pcrd(b, i, j) + pc_up(b, i, j) + pc_down(b, i, j) + pc_right(b, i, j) + pc_left(b, i, j);
}
int getr(BOARD b, int i, int j) {
    return pc_up(b, i, j) + pc_down(b, i, j) + pc_right(b, i, j) + pc_left(b, i, j);
}
int getb(BOARD b, int i, int j) {
    return pcldu(b, i, j) + pcldd(b, i, j) + pcru(b, i, j) + pcrd(b, i, j);
}
int getkn(BOARD b, int i, int j) {
    //This Bug, I tell you :/
    static int moves[4][2] = {{-1, -1}, {1, -1},  {1, 1}, {-1, 1}};
    int ans = 0;
    for(int m = 0; m < 4; m++) {
        int ti = i + moves[m][0];
        int tj = j + moves[m][1];
        if(ti < 0 || tj < 0 || ti >= R || tj >= C) continue;
        if(b[ti][tj] != '.') {
            ans++;
        }
    }
}

int res(BOARD b) {
    int ans = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(b[i][j] == 'P') {
                //cout << "Pawn kills : " << getp(b, i, j) << "\n";
                ans += getp(b, i, j);
            } else if(b[i][j] == 'K') {
                //cout << "King kills : " << getk(b, i, j) << "\n";
                ans += getk(b, i, j);
            } else if(b[i][j] == 'R') {
                ans += getr(b, i, j);
            } else if(b[i][j] == 'B') {
                ans += getb(b, i, j);
            } else if(b[i][j] == 'Q') {
                ans += getq(b, i, j);
            } else if(b[i][j] == 'N') {
                ans += getkn(b, i, j);
            }
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        int n;
        cin >> n;

        BOARD b(8, string(8, '.'));
        for(int i = 0; i < n; i++) {
            char posn, posc, type;
            string str;
            cin >> str;
            posc = str[0];
            posn = str[1];
            type = str[3];
            //cout << "\n" << posc << " " << posn << " " << type;
            addBoard(b, posc, posn, type);
        }
        cout << res(b) << "\n";
        /*
        cout << "\n";
        for(int i = 0; i < 8; i++) {
                cout << b[i] << "\n";
        }
        */
    }
    return 0;
}
