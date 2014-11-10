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
bool is_integer(double k)
{
    return std::floor(k) == k;
}
ll getn2(ll r) {
    if(r == 0) {
        return 1;
    }
    double x = 0;
    ll c = 0;
    double rr = r;
    ll limit = sqrt(r);
    while(x <= limit) {
        if(is_integer(sqrt(rr - (x * x)))) {
            c++;
        }
        x++;
    }
    return 4ll * c - 4ll;
}
int main() {
    int t;
    ll r, k;

    scanf("%d", &t);
    fr(i, t) {
        scanf("%lld%lld", &r, &k);
        ll numSol = getn2(r);
        if(k >= numSol) {
            printf("possible\n");
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}

