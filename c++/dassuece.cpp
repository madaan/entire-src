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
#define MAX 1100
ll dp[MAX][MAX];
ll val[MAX][MAX];
int n, m, q;
ll getmax(int i, int j) {
    if(i < 0 || j < 0 || j >= m || i >= n) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(i == (n - 1)) {
        return (dp[i][j] = val[i][j]);
    }
    dp[i + 1][j] = getmax(i + 1, j);
    dp[i + 1][j - 1] = getmax(i + 1, j - 1);
    dp[i + 1][j + 1] = getmax(i + 1, j + 1);
    return (dp[i][j] = val[i][j] + max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1])));
}
int main() {
    int r, c;
    ll v;
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d", &n, &m, &q);
    fr(i, q) {
        scanf("%d%d%lld", &r, &c, &v);
        //printf("%d %d %lld\n", r, c, v);
        val[r][c] += v;
    }
    ll res = 0;
    fr(i, m) {
        //printf("%lld\n", getmax(0, i));
        res = max(res, getmax(0, i));
    }
    printf("%lld\n", res);
    return 0;
}

