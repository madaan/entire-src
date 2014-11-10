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
#define MAX 110
int dp[MAX][MAX];
int a[MAX][MAX];
int n, m;
int getmax(int i, int j) {
    if(i < 0 || i >= n || j >= m || j < 0) {
        return dp[i][j] = 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int res = 1;
    if(a[i + 1][j] > a[i][j]) {
        dp[i + 1][j] = getmax(i + 1, j);
        res = dp[i + 1][j] + 1;
    }
    if(a[i][j + 1] > a[i][j]) {
        dp[i][j + 1] = getmax(i, j + 1);
        res = max(res, dp[i][j + 1] + 1);
    }
    return dp[i][j] = res;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &n, &m);
        fr(i, n)
        fr(j, m)
        scanf("%d", &a[i][j]);
        printf("%d\n", getmax(0, 0));
    }
    return 0;
}
