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
typedef pair<ll, ll> pll;
typedef vector<string> vs;
 
// Basic macros
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
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
const ll oo = 2000000009;
const double eps = 1e-9;
#define MAX 100009
vector<pll> numberDist;
int nodeComponentMap[MAX];
int main() {
    ll n, p, k;
    scanf("%lld%lld%lld", &n, &k, &p);
    ll dist;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &dist);
        numberDist.pu(pll(dist, i));
    }

    sort(all(numberDist));
    
    ll componentNumber = 1;
    pll firstNode = numberDist[0];
    ll nodenumber = firstNode.second;
    ll prevDist = firstNode.first;
    nodeComponentMap[nodenumber] = componentNumber;
    tr(numberDist, i) {
        ll dist = i->first;
        nodenumber = i->second;
        if(dist - prevDist > k) {
            componentNumber++;
        } 
        nodeComponentMap[nodenumber] = componentNumber;
        prevDist = dist;
    }
    ll n1, n2;
    for(ll i = 1; i <= p; i++) {
        scanf("%lld%lld", &n1, &n2);
        if(nodeComponentMap[n1] == nodeComponentMap[n2]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}


