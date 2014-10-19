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


ll solve(int r, int g, int l) {
    
    //cout << "solve(" << r << ", " << 
    if(l == 0) {
        return 0;
    }
    if(r == 0) {
        if(g >= (l * (l + 1) / 2)) {
            return 1;
        } else {
            return 0;
        }
    }
    if(g == 0) {
        if(r >= (l * (l + 1) / 2)) {
            return 1;
        } else {
            return 0;
        }
    }
    ll res = 0;
    if(r >= l) {
        res += solve(r - l, g, l - 1);
    }
    if(g >= l) {
        res += solve(r, g - l, l - 1);
    }
    return res;
}

int maxl(int t) {
    return (-1 + sqrt(4 * t + 1)) / 2;
}

int main() {
    int r, g;
    cin >> r >> g;
    cout << maxl(2 * (r + g)) << "\n";
    cout << solve(r, g, maxl(2 * (r + g))) << "\n";
    return 0;
}
