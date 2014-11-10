//sg
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;
const ll MOD =  1000000007l;
ll a, b;
ll xf;
bool rangeCheck(ll k) {
    return (xf + k * b <= a * b + b - 1);
}
ll getmaxk() {
    ll left = 1, right = 2;
    while(rangeCheck(right)) {
        left = right;
        right *= 2;
    }
    while(left < right - 1) {
        ll mid = left + (right - left) / 2;
        if(rangeCheck(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}
void solve() {
    ll res = 0;
    for(int mod = 1; mod < b; mod++) {
        xf = ((b + 1) / b) * b + mod;
        ll kmax = getmaxk();
        ll ksum = (((kmax) * (kmax + 1)) / 2) % MOD;
        ksum = (b * ksum) % MOD;
        ksum = ksum + (xf * (kmax + 1)) % MOD;
        res = (res + ksum) % MOD;
    }
    cout << res << "\n";
}
int main() {
    cin >> a >> b;
    solve();
    return 0;
}
