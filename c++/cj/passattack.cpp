//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200
const ll MOD = 1000000007l;
ll dp[MAX][MAX];
long long C[101][101],V[101][101];

void init() {
	for (int i=0;i<=100;i++){
		C[i][0] = C[i][i] = 1;
		for (int j=1;j<i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
}


ll abmodn(ll a, ll b, ll n) {
    ll res = 1;
    while (b)
    {
        if (b % 2) {
            res = (res * a) % n;
        }

        a = (a * a) % n;
        b /= 2;
    }

    return res;
}

ll fac(ll a) {
    ll res = 1;
    for(ll j = 1; j <= a; j++) {
        res = (res * j) % MOD;
    }
    return res;
}

ll mod(ll a, ll b) {
    return (a % b + b) % b;
}


ll solve(int n, int m) {
    if(dp[n][m] != -1) {
        return dp[n][m];
    }
    if(m == 0) {
        return dp[n][m] = 0;
    }
    if(m == 1) {
        return dp[n][m] = 1;
    }
    if(m == n) {
        return dp[n][m] = fac(n);
    }
    ll res = abmodn(m, n, MOD);
    ll temp = 0;
    for(int i = 1; i < m; i++) {
        temp += (C[m][i] * solve(n, m - i));
    }
    dp[n][m] = mod(res + mod(-temp, MOD), MOD);
    //cout << "solve(" << n << ", " << m << ") = " << dp[n][m] << "\n";
    return dp[n][m];
}



int main() {
    int t;
    cin >> t;
    init();
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int m, n;
        cin >> m >> n;
        memset(dp, -1, sizeof(dp));
        cout << solve(n, m) << "\n";
    }
    return 0;
}
