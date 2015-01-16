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
#define MAX 100005
list<int> adj[MAX];
int label[MAX];
ll dp[MAX][2];
const ll MOD = 1000000007;
//dp[v][k] is the number of ways of dividing the tree such that the subtree
//rooted at v has k black vertices and all the other subtrees have exactly one black vertex
void numWays(int v, int p) {
    dp[v][0] = 1 - label[v];
    dp[v][1] = label[v];
    tr(adj[v], u) if(*u != p) {
        ll cum[2];
        numWays(*u, v);
        cum[0] = dp[v][0];
        cum[1] = dp[v][1];
        dp[v][0] = dp[v][1] = 0;
        //child u is included
        dp[v][1] += dp[*u][0] * cum[1];
        dp[v][1] %= MOD;
        dp[v][1] += dp[*u][1] * cum[0];
        dp[v][1] %= MOD;
        dp[v][0] += dp[*u][0] * cum[0];
        dp[v][0] %= MOD;
        //child u is not included
        dp[v][1] += dp[*u][1] * cum[1];
        dp[v][1] %= MOD;
        dp[v][0] += dp[*u][1] * cum[0];
        dp[v][0] %= MOD;
    }
}
int main() {
    int n, temp;
    scanf("%d", &n);
    fr(i, n - 1) {
        scanf("%d", &temp);
        adj[i + 1].pu(temp);
        adj[temp].pu(i + 1);
    }
    fr(i, n) {
        scanf("%d", &label[i]);
    }
    numWays(0,-1);
    cout << dp[0][1] << endl;
    return 0;
}
