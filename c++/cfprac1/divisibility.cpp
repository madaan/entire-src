//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 10009
int dp[MAX][100];
int mod(int a, int b) {
    return (a % b + b) % b;
}


int main() {
    
    int n, k;
    cin >> n >> k;
    int arr[MAX];
    int kl = k - 1;
    scanf("%d", &arr[0]);
    dp[0][mod(arr[0], k)] = 1;
    for(int i = 1; i < n; i++) {
        scanf("%d", &arr[i]);
        for(int m = 0; m < k; m++) {
            if(dp[i - 1][m] == 1) {
                dp[i][mod((m + arr[i]), k)] = 1;
                dp[i][mod((m - arr[i]), k)] = 1;
            }
        }
    }
    if(dp[n - 1][0]) {
        printf("Divisible\n");
    } else {
        printf("Not divisible\n");
    }
    return 0;
}
    


