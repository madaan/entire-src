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
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
const int oo = 2000000009;
const double eps = 1e-9;
int main() {
    ll n, m, h;
    scanf("%lld%lld%lld", &n, &m, &h);
    ll t, c;
    vector<pi> costs;
    ll totalCells = 0;
    for(int i = 0; i < h; i++) {
        scanf("%lld%lld", &t, &c);
        totalCells += t;
        costs.pu(pi(c, t));
    }
    if(totalCells < n * m) {
        printf("Impossible\n");
        return 0;
    }
    sort(all(costs));
    ll cost = 0;
    ll cells = n * m;
    ll cellsCovered = 0;
    ll cellsToCover = n * m;
    tr(costs, i) {
        pi curr = *i;
        cellsCovered = (curr.second < cellsToCover  ? curr.second : cellsToCover);
        cellsToCover = cellsToCover - cellsCovered;
        cost += (curr.first * cellsCovered);
        if(cellsToCover <= 0) {
            break;
        }
    }
    printf("%lld\n", cost);
    return 0;
}
