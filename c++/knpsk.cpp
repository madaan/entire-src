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
#define MAX 100005
ll dp[MAX];
const int oo = 2000000009;
const double eps = 1e-9;
vector<pi> w2Items, w1Items, items;
//returns the cheapest item for a given wt
ll cheapest(ll wt) {
    ll w = wt;
    ll costc = 0;
    ll wcum = 0;
    tr(items, i) {
        pi curr = *i;
        ll wtcurr = curr.second;
        ll cost = curr.first;
        wcum += wtcurr;
        costc += cost;
        if(wcum == wt) {
            return costc;
        }
        else if(wcum == wt - 1) { //need to find something ahead
            wcum -= wtcurr;
            costc -= cost;
        }
    }
    return -1; //cannot find the right wt
}
ll minv[MAX];
int num2, num1;
ll M = 0;
ll SUM;
void makeMin() {
    minv[0] = 0;
    minv[1] = w1Items[0].first;
    minv[2] = w2Items[0].first;
    int even = 1, odd = 1;
    ll e, o;
    for(int i = 3; i <= M; i++) {
        //try even
        e = o = oo;
        if(i % 2 == 0) {
            if(even < num2) {
                e = minv[i - 2] + w2Items[even].first;
            }
            if(odd < num1) {
                o = minv[i - 1] + w1Items[odd].first;
            }
            if(e < o) {
                minv[i] = e;
                even++;
            } else {
                minv[i] = o;
                odd++;
            }
        } else {
            minv[i] = 2; //TODO
        }
        for(int i = 0; i <= M; i++) {
            printf("minv[%d] = %lld\n", i, minv[i]);
        }
    }
    void printRange() {
        for(int i = 1; i <= M; i++) {
            printf("%lld ", SUM - minv[M - i]);
        }
        printf("\n");
    }
    int main() {
        ll n;
        scanf("%lld", &n);
        ll w, c;
        for(int i = 0; i < n; i++) {
            scanf("%lld%lld", &w, &c);
            M += w;
            SUM += c;
            if(w == 1) {
                w1Items.pu(pi(c, w));
            } else {
                w2Items.pu(pi(c, w));
            }
            items.pu(pi(c, w));
        }
        num1 = w1Items.size();
        num2 = w2Items.size();
        sort(all(w2Items));
        sort(all(w1Items));
        //sort(all(items));
        makeMin();
        printRange();
        return 0;
    }
