//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int dp[MAX];
int arr[1000];
/*
 * This will work only if the jump is binary: can take/can't take types
 */
int solve(int n) {
    dp[0] = 0;
    for(int i = 1; i <= n - 1; i++) {
        int dest = (i + arr[i]);
        if(dest >= n) {
            dest = n - 1;
        }
        dp[dest] = min(dp[dest], i + 1);
        if(dp[i] != 0) {
            dp[dest] = min(dp[dest], dp[i] + 1);
        }
    }
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        dp[i] = 10000000;
        scanf("%d", arr + i);
    }
    cout << solve(n) << "\n";
    return 0;
}
