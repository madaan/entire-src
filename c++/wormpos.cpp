//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    ll temp;
    cin >> n;
    vector<ll> vals(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        vals[i] = vals[i - 1] + temp;
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> temp;
        cout << distance(vals.begin(), lower_bound(vals.begin() + 1, vals.begin() + n, temp)) << "\n";
    }
    return 0;
}
