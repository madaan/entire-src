//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< vector< int > > MAT;
vector<int> up(vector<int> ip) {
    vector< int > res(ip.size() + 1, 0);
    int j = 0;
    for(int i = 0; i  < ip.size() - 1; i++, j++) {
        if(ip[i] == ip[i + 1]) {
            res[j] = ip[i] * 2;
            i++;
        } else {
            res[j] = ip[i];
        }
    }
    return res;
}
void print(MAT m, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}
void xpose(MAT &ip, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = i + 1; j < c; j++) {
            ip[i][j] ^= ip[j][i];
            ip[j][i] ^= ip[i][j];
            ip[i][j] ^= ip[j][i];
        }
    }
}
void upmat(MAT &ip, int r, int c) {
    for(int j = 0; j < c; j++) {
        int ptr = 0;
        //first move all the zeroes up
        int i = 0;
        vector<int> nc(r, 0);
        int nptr = 0;
        for(i = 0; i < r; i++) {
            if(ip[i][j] != 0) {
                nc[nptr++] = ip[i][j];
            }
        }
        for(i = 0; i < r; i++) {
            ip[i][j] = nc[i];
        }
        for(int i = 0; i < r; i++, ptr++) {
            if(i < r - 1 && ip[i][j] == ip[i + 1][j]) {
                ip[ptr][j] = ip[i][j] * 2;
                i++;
            } else {
                ip[ptr][j] = ip[i][j];
            }
        }
        for(; ptr < r; ptr++) {
            ip[ptr][j] = 0;
        }
    }
}
void downmat(MAT &ip, int r, int c) {
    for(int j = 0; j < c; j++) {
        int ptr = r - 1;
        int i = 0;
        vector<int> nc(r, 0);
        int nptr = r - 1;
        for(i = r - 1; i >= 0; i--) {
            if(ip[i][j] != 0) {
                nc[nptr--] = ip[i][j];
            }
        }
        for(i = 0; i < r; i++) {
            ip[i][j] = nc[i];
        }
        for(int i = r - 1; i >= 0; i--, ptr--) {
            if(i > 0 && ip[i][j] == ip[i - 1][j]) {
                ip[ptr][j] = ip[i][j] * 2;
                i--;
            } else {
                ip[ptr][j] = ip[i][j];
            }
        }
        for(; ptr >= 0; ptr--) {
            ip[ptr][j] = 0;
        }
    }
}
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d:\n", qq);
        int n;
        string dir;
        cin >> n >> dir;
        MAT mat(n, vector< int> (n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        if(dir == "up") {
            upmat(mat, n, n);
        } else if(dir == "right") {
            xpose(mat, n, n);
            downmat(mat, n, n);
            xpose(mat, n, n);
        } else if(dir == "left") {
            xpose(mat, n, n);
            upmat(mat, n, n);
            xpose(mat, n, n);
        } else {
            downmat(mat, n, n);
        }
        print(mat, n, n);
    }
    return 0;
}

