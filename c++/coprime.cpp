
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
int main() {
    ll l, r;
    cin >> l >> r;
    int elems = r - l + 1;
    if(elems <= 2) {
        cout << "-1\n";
    } else if(elems <= 3) {
        if(l % 2) { //not possible with odd
            cout << "-1\n";
        } else {
            cout << l << " " << l + 1 << " " << l + 2 << "\n";
        }
    } else {
        if(l % 2) {
            cout << l + 1 << " " << l + 2 << " " << l + 3 << "\n";
        } else {
            cout << l << " " << l + 1 << " " << l + 2 << "\n";
        }
    }
    return 0;
}
