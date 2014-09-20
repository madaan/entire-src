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
ll n, a, b;
ll target;

ll binsearch() {
    ll l = 1;
    ll r = 6000000000ll;
    ll mid;
    while(l < r) {
        mid = l + ((r - l + 1ll) / 2ll);
        if(target < mid) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}


int main() {
    cin >> n >> a >> b;
    
    double target = 6ll * n;
    if(target <= (a * b)) {
        cout << (a * b) << "\n" << a << " " << b << "\n";
        return 0;
    }

    ll na = ceil(target / b);
    ll nb = ceil(target / a);
    ll a1 = a * nb;
    ll a2 = na * b;
    if(a1 < a2 && (nb >= b)) {
        cout << target << "\n" << a << " " << nb << "\n";
    } else {
        cout << target << "\n" << na << " " << b << "\n";
    }
    return 0;
}

