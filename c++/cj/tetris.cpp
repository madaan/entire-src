//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< string > BOARD;
typedef vector< string > PIECE;

bool isComp(char a, char b) {
    return (a == '.' || b == '.');
}

bool putPiece(PIECE p, BOARD &b, int col, int row) {
    int ph = p.size();
    int pw = p[0].length();
    int br = row - ph + 1;
    if(br < 0) {
        return false;
    }
    for(int i = 0; i < ph; i++) {
        for(int j = 0; j < pw; j++) {
            if(!isComp(b[i + br][j + col], p[i][j])) {
                return false;
            } else {
                b[i + br][j + col] = p[i][j] == '.' ? b[i + br][j + col] : p[i][j];
            }
        }
    }
}

bool canPlace(PIECE p, BOARD b, int col, int lastRow) {
    int ph = p.size();
    int pw = p[0].length();
    int br = lastRow - ph + 1;
    if(br < 0) {
        return false;
    }
    for(int i = 0; i < ph; i++) {
        for(int j = 0; j < pw; j++) {
            if(!isComp(b[i + br][j + col], p[i][j])) {
                return false;
            }
        }
    }
    return true;
}


    

int place(PIECE &p, BOARD &b, int x, vector< int > &top) {
    int span = p[0].length();
    int topmost = top[x];
    for(int i = 1; i < span; i++) {
        if(topmost > top[x + i]) {
            topmost = top[x + i];
        }
    }
    //cout << x << " " << topmost << "\n";
    //the piece will be placed starting from the lower left coordinates of
    //x and topmost
    int lastRow = b.size() - 1;
    while(lastRow >= 0) {
        if(canPlace(p, b, x, lastRow)) {
            putPiece(p, b, x, lastRow);
            break;
        } else {
            lastRow--;
        }
    }
    if(lastRow < 0) {
        return -1;
    }
    return 1;
}

void dumpBoard(BOARD &b) {
    int h = b.size();
    int w = b[0].length();
    for(int i = 0; i < h; i++) {
        cout << b[i] << "\n";
    }
}

bool lineDel(string x) {
    return (x.find('.') == string::npos);
}

BOARD lineMerge(BOARD &b) {
    int bh = b.size();
    int bw = b[0].length();
    BOARD bup(bh, string(bw, '.'));
    int j = bh - 1;
    for(int i = bh - 1; i >= 0; i--) {
        if(!lineDel(b[i])) {
            bup[j] = b[i];
            j--;
        }
    }
    return bup;
}


int main() {
    const char *p11[] = {"x.", "xx", ".x"};
    const char *p12[] = {".xx", "xx."};
    const char *p13[] = {"x.", "xx", ".x"};
    const char *p14[] = {".xx", "xx."};
    const char *p21[] = {".x", "xx", "x."};
    const char *p22[] = {"xx.", ".xx"};
    const char *p23[] = {".x", "xx", "x."};
    const char *p24[] = {"xx.", ".xx"};
    const char *p31[] = {"x.", "x.", "xx"};
    const char *p32[] = {"..x", "xxx"};
    const char *p33[] = {"xx", ".x", ".x"};
    const char *p34[] = {"xxx", "x.."};
    const char *p41[] = {".x", ".x", "xx"};
    const char *p42[] = {"xxx", "..x"};
    const char *p43[] = {"xx", "x.", "x."};
    const char *p44[] = {"x..", "xxx"};
    const char *p51[] = {"xx", "xx"};
    const char *p52[] = {"xx", "xx"};
    const char *p53[] = {"xx", "xx"};
    const char *p54[] = {"xx", "xx"};
    const char *p61[] = {"x", "x", "x", "x"};
    const char *p62[] = {"xxxx"};
    const char *p63[] = {"x", "x", "x", "x"};
    const char *p64[] = {"xxxx"};
    const char *p71[] = {".x.", "xxx"};
    const char *p72[] = {".x", "xx", ".x"};
    const char *p73[] = {"xxx", ".x."};
    const char *p74[] = {"x.", "xx", "x."};

    PIECE p[] = {
        vector<string>(p11, p11 + 3),
        vector<string>(p12, p12 + sizeof(p12) / sizeof(p12[0])),
        vector<string>(p13, p13 + sizeof(p13) / sizeof(p13[0])),
        vector<string>(p14, p14 + sizeof(p14) / sizeof(p14[0])),
        vector<string>(p21, p21 + sizeof(p21) / sizeof(p21[0])),
        vector<string>(p22, p22 + sizeof(p22) / sizeof(p22[0])),
        vector<string>(p23, p23 + sizeof(p23) / sizeof(p23[0])),
        vector<string>(p24, p24 + sizeof(p24) / sizeof(p24[0])),
        vector<string>(p31, p31 + sizeof(p31)/sizeof(p31[0])),
        vector<string>(p32, p32 + sizeof(p32)/sizeof(p32[0])),
        vector<string>(p33, p33 + sizeof(p33)/sizeof(p33[0])),
        vector<string>(p34, p34 + sizeof(p34)/sizeof(p34[0])),
        vector<string>(p41, p41 + sizeof(p41) / sizeof(p41[0])),
        vector<string>(p42, p42 + sizeof(p42) / sizeof(p42[0])),
        vector<string>(p43, p43 + sizeof(p43) / sizeof(p43[0])),
        vector<string>(p44, p44 + sizeof(p44) / sizeof(p44[0])),
        vector<string>(p51, p51 + sizeof(p51) / sizeof(p51[0])),
        vector<string>(p52, p52 + sizeof(p52) / sizeof(p52[0])),
        vector<string>(p53, p53 + sizeof(p53) / sizeof(p53[0])),
        vector<string>(p54, p54 + sizeof(p54) / sizeof(p54[0])),
        vector<string>(p61, p61 + sizeof(p61) / sizeof(p61[0])),
        vector<string>(p62, p62 + sizeof(p62) / sizeof(p62[0])),
        vector<string>(p63, p63 + sizeof(p63) / sizeof(p63[0])),
        vector<string>(p64, p64 + sizeof(p64) / sizeof(p64[0])),
        vector<string>(p71, p71 + sizeof(p71) / sizeof(p71[0])),
        vector<string>(p72, p72 + sizeof(p72) / sizeof(p72[0])),
        vector<string>(p73, p73 + sizeof(p73) / sizeof(p73[0])),
        vector<string>(p74, p74 + sizeof(p74) / sizeof(p74[0]))
    };
    vector<PIECE> piece(p, p + sizeof(p) / sizeof(p[0]));

    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d:\n", tt);
        int w, h, n;
        cin >> w >> h >> n;
        BOARD b(h, string(w, '.'));
        vector< int > top(w, h - 1); //stores the top of each row, note that value is tweaked to mod indexing
        int i = 0;
        int t, r, x;
        bool over = false;
        for(i = 0; i < n; i++) {
            cin >> t >> r >> x;
            if(!over && place(piece[4 * (t - 1) + r], b, x, top) == -1) {
                cout << "Game Over!\n";
                over = true;
            }
            b = lineMerge(b);
        }

        if(!over) {
            dumpBoard(b);
        }
    }
    return 0;
}
