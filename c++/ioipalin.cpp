//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 5010
int n;
int dp[2][MAX];
int lcs(string &a, string &b) {
    int al = n;
    int bl = n;
    for(int i = 1; i <= al; i++) {
        for(int j = 1; j <= bl; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            } else if(dp[(i - 1) % 2 ][j] > dp[i % 2][j - 1]) {
                dp[i % 2 ][j] = dp[(i - 1) % 2][j];
            } else {
                dp[i % 2][j] = dp[i % 2][j - 1];
            }
        }
    }
    return dp[al % 2][bl];
}
void rev(string &a) {
    for(int i = 0; i < n / 2; i++) {
        a[i] ^= a[n - i - 1];
        a[n - i - 1] ^= a[i];
        a[i] ^= a[n - i - 1];
    }
}
int main() {
    char a[5005];
    scanf("%d", &n);
    scanf("%s", a);
    string a_str(a);
    string b(a_str);
    //rev(a_str);
    reverse(a_str.begin(), a_str.end());
    //cout << a_str << "\n";
    printf("%d\n", n - lcs(a_str, b));
    return 0;
}
