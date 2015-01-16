//sg
#include <stdio.h>
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
typedef vector<long long> vi;
typedef pair<long long,long long> pi;
typedef vector<string> vs;
// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(long long i=s;i<(n);++i)
#define rep(i,s,n)  for(long long i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(long long i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (long long)(x.size())
vector<pi> vp;
#define MAX 1000010
class BIT
{
    long long *tree;
    long long MAXINDEX;
public:
    BIT(long long mi):MAXINDEX(mi)
    {
        tree = new long long[MAXINDEX + 1];
    }
    //returns the cumulative frequency at the given position
    long long read(long long loc)
    {
        long long ret = 0;
        while(loc > 0) {
            ret += tree[loc];
            loc = loc - (loc & -loc);
        }
        return ret;
    }
    //updates the cumulative frequency at all the required places
    void update(long long loc, long long val)
    {
        while(loc <= MAXINDEX) {
            tree[loc] += val;
            loc = loc + (loc & -loc);
        }
    }
    void setmax(long long in)
    {
        MAXINDEX = in;
    }
    void refresh()
    {
        memset(tree, 0, sizeof(long long)*(MAXINDEX + 1));
        //ini(tree, 0);
    }
};
int main()
{
    int T;
    int n, m, k;
    scanf("%d", &T);
    BIT bt(1100);
    fr(t, T) {
        long long crossing = 0;
        scanf("%d%d%d", &n, &m, &k);
        bt.setmax(m);
        long long e, w;
        fr(i, k) {
            scanf("%lld%lld", &e, &w);
            vp.pu(mp(e, w));
        }
        sort(all(vp));
        bt.refresh();
        for(long long i = k - 1; i >= 0; i--) {
            //same island on east coast cannot add to the long longersections
            long long j;
            for(j = i; j >= 0 && vp[i].st == vp[j].st; j--) {
                crossing += bt.read(vp[j].se - 1);
            }
            for(j = i; j >= 0 && vp[i].st == vp[j].st; j--) {
                bt.update(vp[j].se, 1);
            }
            i = j + 1;
        }
        printf("Test case %lld: %lld\n", t + 1, crossing);
        vp.clear();
    }
    return 0;
}
