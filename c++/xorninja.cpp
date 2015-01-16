//sg
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[100009];
ll a[100009];
int n;
ll solve() {
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        dp[i] += (a[i] + a[i]^dp[i - 1]) % 1000000007;
    }
    return dp[n - 1];
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        cout << solve() << "\n";
    }
    return 0;
}
