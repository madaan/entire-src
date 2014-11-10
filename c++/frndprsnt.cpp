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

typedef long long ll;
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
bool check(ll n, ll cnt, ll p) {
    return (n - (n / p)) < cnt;
}
//returns the first n for which there are sufficient elements
//that when div by p do not leave a remainder
ll firstn(ll cnt, ll p) {
    ll l = 0, r = 1;
    while(check(r, cnt, p)) {
        l = r;
        r = r * 2;
    }
    while(r - l > 1) {
        ll mid = l + (r - l) / 2;
        if(check(mid, cnt, p)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l + 1;
}
ll gcd(ll a, ll b) {
    while(b) {
        ll tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
ll solve(ll cnt1, ll cnt2, ll x, ll y) {
    ll n = firstn(cnt1, x);
    //cout << n << "\n";
    ll lcxy = (x * y) / gcd(x, y);
    ll nc2 = 0;
    nc2 += cnt2;
    nc2 -= ((n / x) - (n / lcxy));
    //cout << nc2 << "\n";
    if(nc2 <= 0) { //already done
        return n;
    }
    nc2 += (n - n / y); //to simulate search from n
    return firstn(nc2, y);
}
int main() {
    ll cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    int r1 = solve(cnt1, cnt2, x, y);
    int r2 = solve(cnt2, cnt1, y, x);
    cout << min(r1, r2) << "\n";
    return 0;
}
