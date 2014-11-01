//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
typedef long long ll;
const ll MOD = 1000000007;
ll num[MAX], den[MAX];
ll fastexp(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b % 2) {
            res = (res * a) % c;
        }
        b = b / 2;
        a = (a * a) % c;
    }
    return res;
}
void fill() {
    num[0] = num[1] = 1;
    
    for(int i = 2; i < MAX; i++) {
        num[i] = (num[i - 1] * i) % MOD;
    }
    den[MAX - 1] = fastexp(num[MAX - 1], MOD - 2, MOD);
    for(int i = MAX - 2; i >= 0; i--) {
        den[i] = ((i + 1) * den[i + 1]) % MOD;
    }
}

ll nck(int n, int k) {
    ll res = num[n];
    res = (res * den[k]) % MOD;
    res = (res * den[n - k]) % MOD;
    return res;
}

int main() {
    int t;
    fill();
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector< ll > nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        ll res = 0;
        for(int i = 0; i < n && (n - i) >= k; i++) {
            res = (res + ((nums[i]) * (nck(n - i - 1, k - 1)))) % MOD;
        }
        cout << res << "\n";
    }
    return 0;
}
