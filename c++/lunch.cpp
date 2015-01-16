//sg
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MAX 100010
ll dp[MAX];
ll ans[MAX];
const ll MOD = 1000000007l;
int n, k;
ll mod(ll a, ll b) {
    return (a % b + b) % b;
}
void fill() {
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if((i - k) >= 0) {
            dp[i] = (dp[i] + dp[i - k]) % MOD;
        }
    }
}
void dpCum() {
    ans[0] = dp[0];
    for(int i = 1; i <= n; i++) {
        ans[i] = (ans[i - 1] + dp[i]);
    }
}
int main() {
    int t, a, b;
    n = MAX - 1;
    cin >> t >> k;
    fill();
    dpCum();
    for(int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << mod(ans[b] - ans[a - 1], MOD) << "\n";
    }
    return 0;
}
