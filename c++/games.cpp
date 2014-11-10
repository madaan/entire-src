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
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<string> vs;

// Basic macros
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(ll i=s;i<(n);++i)
#define rep(i,s,n)  for(ll i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(ll i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (ll)(x.size())

const ll oo = 2000000009;
const double eps = 1e-9;
ll gcd(ll a, ll b) {
    ll temp;
    while(b) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int t;
    double ip;
    scanf("%d", &t);
    string s;
    for(ll j = 0; j < t; j++) {
        cin >> s;
        int i = 0;
        int l = s.length();
        for(i = 0 ; i < l; i++) {
            if(s[i] == '.') {
                i++;
                break;
            }
        }
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        bool changed = true;
        ll den = pow(10, l - i);
        ll num = atoi(s.c_str());
        //cout << den << "\n";
        printf("%lld\n", den / gcd(num, den));
    }
    return 0;
}
