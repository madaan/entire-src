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
#define  N  105
#define P  5100
ll MOD = 1000000007l;
int arr[N][N];
ll dp[N][N][P + 20];
int n, c;

void fill() {
    dp[1][1][arr[1][1]] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k <= P; k++) {
                if(dp[i - 1][j][k] != 0) {
                    dp[i][j][k + arr[i][j]] = (dp[i][j][k + arr[i][j]] + dp[i - 1][j][k]) % MOD;
                }
                if(dp[i][j - 1][k] != 0) {
                    dp[i][j][k + arr[i][j]] = (dp[i][j][k + arr[i][j]] + dp[i][j - 1][k]) % MOD;
                }
                //if(dp[i][j][k + arr[i][j]])
                //cout << i << " " << j << " " << k + arr[i][j] << " " << dp[i][j][k + arr[i][j]] << "\n";
            }
        }
    }
    int maxP = 0;
    int i;
    for(i = P; i >= 0 && dp[n][n][i] == 0; i--) {
    }
    maxP = i;
    //cout << maxP << "\n";
    if(c >= maxP) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << maxP << " " << dp[n][n][maxP] << "\n";
}

                

int main() {
    int temp;
    //memset(dp, -1, sizeof(dp));
    cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    fill();
    return 0;
}
