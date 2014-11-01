//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int dp[MAX];
int arr[1000];
int solve(int n) {
    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        for(int j = i + 1; j <= i + arr[i]; j++) {
            dp[i] = min(dp[i], 1 + dp[j]);
        }
    }
    return dp[1];
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        dp[i] = 1100;
        scanf("%d", arr + i);
    }
    cout << solve(n) << "\n";
    return 0;
}
