//sg
#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve(int arr[], int n, int i) {
    if(dp[i] != -1) {
        return dp[i];
    }
    if(i >= n - 1) {
        return dp[i] = 0;
    }
    if(arr[i] == 0) {
        return dp[i] = 1 + solve(arr, n, i + 1);
    }
    int ans = 1 + min(solve(arr, n, i + 1), solve(arr, n, i + arr[i]));
    return dp[i] = ans;
}


int jump(int A[], int n) {
    dp = vector<int> (n + 1, -1);
    return solve(A, n, 0);
}
int main() {
    //int arr[] = {2, 3, 1, 1, 4};
    int arr[] = {1, 2, 0, 1};
    cout << jump(arr, 4) << "\n";
    return 0;
}
