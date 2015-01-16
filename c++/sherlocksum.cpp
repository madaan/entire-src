//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
typedef long long ll;
ll dp[2][MAX];
int n;
ll arr[MAX];
//solve for i onwards, taken i - 1th to be prev
ll solve(int prev, int i) {
    if(dp[prev][i] != -1) {
        return dp[prev][i];
    }
    if(i >= n) {
        return 0ll;
    }
    ll pval = 0;
    if(prev == 0) {
        pval = 1;
    } else {
        pval = arr[i - 1];
    }
    ll res1 = abs(pval - 1) + solve(0, i + 1); //take ith = 1 here
    ll res2 = abs(pval - arr[i]) + solve(1, i + 1);
    return dp[prev][i] = max(res1, res2);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << max(solve(0, 1), solve(1, 1)) << "\n";
    }
    return 0;
}
