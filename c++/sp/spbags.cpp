//sg
#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
#define S 15
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
ll dp[MAXN][S];


int solve(vi bag, int N) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    dp[0][bag[0]] = true;
    for(int i = 1; i < N; i++) {
        for(int s = 0; s < S; s++) {
            if((s - bag[i]) >= 0)
                dp[i][s] = (dp[i - 1][s] + dp[i - 1][s - bag[i]]);
            else
                dp[i][s] = dp[i - 1][s];

        }

    }
    vector< bool > isPrime(S, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < S; i++) {
        if(isPrime[i]) for(int j = i * 2; j < S; j += i) {
                isPrime[j] = false;
            }
    }

    ll res = 0;
    for(int i = 0; i < S; i++) {
        if(isPrime[i] && dp[N - 1][i]) {
            res += dp[N - 1][i];
        }
    }
    return res;
}


int main() {
    int arr[] = {1, 1, 2, 7};
    vi v(arr, arr + 4);
    cout << solve(v, 4) << "\n";
    return 0;
}
