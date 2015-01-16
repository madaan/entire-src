//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 110
int dp[MAX][MAX];
char path[MAX][MAX];
string a, b;
int al, bl;
int findname(int i, int j) {
    //printf("findname(%d, %d)\n", i, j);
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j]) {
        path[i][j] = 'x';
        return dp[i][j] = 1 + findname(i + 1, j + 1);
    } else if(i >= al) {
        return dp[i][j] = bl - j;
    } else if(j >= bl) {
        return dp[i][j] = al - i;
    } else {
        int r1 = findname(i + 1, j);
        int r2 = findname(i, j + 1);
        if(r1 < r2) { //take r1, go down
            path[i][j] = 'd';
        } else {
            path[i][j] = 'r';
        }
        return dp[i][j] = 1 + min(r1, r2);
    }
}
string getval() {
    string res = "";
    int i = 0, j = 0;
    while(i < al && j < bl) {
        if(path[i][j] == 'r') {
            res += b[j];
            j++;
        } else if(path[i][j] == 'd') {
            res += a[i];
            i++;
        } else if(path[i][j] == 'x') {
            res += a[i];
            i++;
            j++;
        }
    }
    if(i < al) {
        res += a.substr(i, al);
    }
    if(j < bl) {
        res += b.substr(j, bl);
    }
    return res;
}
int main() {
    char astr[200], bstr[200];
    while(scanf("%s%s", astr, bstr) != EOF) {
        a = string(astr);
        b = string(bstr);
        al = a.length();
        bl = b.length();
        memset(dp, -1, sizeof(dp));
        findname(0, 0);
        cout << getval() << "\n";
    }
    return 0;
}
