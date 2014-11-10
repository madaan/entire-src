//sg
#include<bits/stdc++.h>
using namespace std;
int arr[100];
bool iscomp(int i, int j) {
    int diff = arr[i] - arr[j];
    return (abs(diff) <= abs(i - j));
}
int dp[100];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = i - 1; j >= 1; j--) {
            if(iscomp(i, j)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i  = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }
    cout << res << "\n";
    return 0;
}
