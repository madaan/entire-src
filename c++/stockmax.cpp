//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 50009
ll a[MAX];
ll cum[MAX];
ll n;


ll solve() {
    ll res = 0;
    vector< ll > bought;
    ll cmax = a[n];
    vector< bool > shouldbuy(n + 1, false);
    for(ll i = n - 1; i > 0; i--) {
        if(a[i] < cmax) {
            shouldbuy[i] = true;
        } else {
            cmax = a[i];
        }
    }

    for(ll i = 1; i <= n - 1; i++) {
        if(shouldbuy[i]) {
            //cout << "buying " << i << "\n";
            bought.push_back(a[i]);
        } else {
            for(ll j = 0; j < bought.size(); j++) {
                res = res + (a[i] - bought[j]);
            }
            bought.clear();
        }
    }
    for(ll j = 0; j < bought.size(); j++) {
        res = res + (a[n] - bought[j]);
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        cin >> n;
        cum[0] = 0;
        for(ll i = 1; i <= n; i++) {
            cin >> a[i];
            cum[i] = a[i] + cum[i - 1];
        }
        cout << solve() << "\n";
    }
    return 0;
}
