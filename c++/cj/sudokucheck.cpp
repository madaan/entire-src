//sg
#include<bits/stdc++.h>
using namespace std;
int mat[1000][1000];
int n, nn;
bool allthere(vector<bool> psnt) {
    for(int i = 1; i <= nn; i++) {
        if(!psnt[i]) {
            return false;
        }
    }
    return true;
}
bool colCheck() {
    bool res = true;
    for(int c = 0; c < nn; c++) {
        vector<bool> psnt(nn + 1, false);
        for(int i = 0; i < nn; i++) {
            if(mat[i][c] > nn) return false;
            psnt[mat[i][c]] = true;
        }
        res = res & allthere(psnt);
        if(!res) {
            return false;
        }
    }
    return res;
}
bool rowCheck() {
    bool res = true;
    for(int r = 0; r < nn; r++) {
        vector<bool> psnt(nn + 1, false);
        for(int c = 0; c < nn; c++) {
            if(mat[r][c] > nn) return false;
            psnt[mat[r][c]] = true;
        }
        res = res & allthere(psnt);
        if(!res) {
            return false;
        }
    }
    return res;
}
bool rangeCheck(int i, int j) {
    vector<bool> psnt(nn + 1, false);
    for(int r = i; r < i + n; r++) {
        for(int c = j; c < j + n; c++) {
            if(mat[r][c] > nn) return false;
            psnt[mat[r][c]] = true;
        }
    }
    return allthere(psnt);
}
bool subcheck() {
    bool res = true;
    for(int i = 0; i < nn; i += n) {
        for(int j = 0; j < nn; j += n) {
            res = res & rangeCheck(i, j);
        }
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        cin >> n;
        nn = n * n;
        for(int i = 0; i < nn; i++) {
            for(int j = 0; j < nn; j++) {
                cin >> mat[i][j];
            }
        }
        if(rowCheck()  && colCheck() && subcheck()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
