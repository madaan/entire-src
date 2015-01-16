//sg
#include<bits/stdc++.h>
using namespace std;
int ln, nn;
double dp[1000][1000];

void spill(int l, int n, double x) {
    //if(dp[l][n] != -1) return dp[l][n];
    //cout << l << " " << n << " " << x << "\n";
    if(x <= 1) {
        dp[l][n] += x;
        return;
    }
    dp[l][n] = 1;
    double spilled = (x - 1) / 2;
    spill(l + 1, n, spilled);
    spill(l + 1, n + 1, spilled);
}

int main() {
    ln = 2, nn = 2;
    spill(1, 1, 2);
    cout << dp[ln][nn] << "\n";
    return 0;
}
