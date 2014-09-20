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
int n, m, k;
#define MAX 5009
ll dp[MAX][MAX];
int arr[MAX];
ll cum[MAX];
ll getmax(int i, int picked) {
    if(dp[i][picked] != -1) {
        return dp[i][picked];
    }
    if(i >= n - m + 2) {
        return dp[i][picked] = 0;
    }
    if(picked >= k) {
        return dp[i][picked] = 0;
    }
    dp[i + m][picked + 1] = getmax(i + m, picked + 1);
    dp[i + 1][picked] = getmax(i + 1, picked);

    return dp[i][picked] = max((cum[i + m - 1] - cum[i - 1] + dp[i + m][picked + 1]), dp[i + 1][picked]);
}



         
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    cum[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        cum[i] = arr[i] + cum[i - 1];
    }
    cout << getmax(1, 0) << "\n";
    return 0;
}

    
