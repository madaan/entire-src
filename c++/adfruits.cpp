//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 110

int dp[MAX][MAX];
char path[MAX][MAX];
string lcs(string a, string b) {
    int al = a.length() - 1;
    int bl = b.length() - 1;

    for(int i = 0; i <= al; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= bl; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= al; i++) {
        for(int j = 1; j <= bl; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = 'd';
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = 'u';
            } else {
                dp[i][j] = dp[i][j - 1];
                path[i][j] = 'l';
            }
        }
    }
    int i = al, j = bl;
    string res;
    while(i > 0 && j > 0) {
        if(path[i][j] == 'u') {
            i--;
        } else if(path[i][j] == 'd') {
            res += a[i];
            i--; j--;
        } else {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}


int main() {
    char a[200], b[200];
    while(scanf("%s%s", a + 1, b + 1) != EOF) {
        string a_str(a + 1);
        string b_str(b + 1);
        string lcs_str = lcs(" "+ a_str, " " + b_str);
        string ans1 = b_left + a_str + b_right;
        string ans2 = a_left + b_str + a_right;
        cout
        if(ans1.length() <= ans2.length()) {
            cout << ans1 << "\n";
        } else {
            cout << ans2 << "\n";
        }
    }
    return 0;
}
