//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(pair <ll, ll>  a, pair<ll, ll> b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
    ll n;
    cin >> n;
    vector< pair< ll, ll > > wts;
    ll w, s;
    for(int i = 0; i < n; i++) {
        cin >> w >> s;
        wts.push_back(pair<ll, ll>(w, s));
    }
    sort(wts.begin(), wts.end(), comp);
    ll res = 0;
    ll cumwt = 0;
    for(int i = wts.size() - 1; i >= 0; i--) {
        res = max(res, cumwt - wts[i].second);
        cumwt += wts[i].first;
    }
    cout << res << "\n";
    return 0;
}


