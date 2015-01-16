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
#define MAX 100009
ll dp[MAX];
ll arr[MAX];
int n;
ll solve(int i) {
    if(i >= n) {
        return oo;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    //take ith
    ll res1 = arr[i] + min(solve(i + 2), min(solve(i + 3), solve(i + 4)));
    ll res2 = arr[i] + arr[i + 1] +  min(solve(i + 2), min(solve(i + 3), solve(i + 4)));
    ll res3 = arr[i] + arr[i + 1] + arr[i + 2] + min(solve(i + 3), min(solve(i + 4), solve(i + 5)));
    return dp[i] = max(res1, max(res2, res3));
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        ini(dp, -1);
        cin >> n;
        fr(i, n) cin >> arr[i];
        cout << solve(0) << "\n";
    }
    return 0;
}
