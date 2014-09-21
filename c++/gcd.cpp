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
map<pi, int> gcdmap;
int dp[100009];
int gcd(int a, int b) {
    if(gcdmap.find(pi(a, b)) != gcdmap.end()) {
        return gcdmap[pi(a, b)];
    }
    int ab = a, bb = b;
    int r, i;
    while(b!=0) {
        r = a % b;
        a = b;
        b = r;
    }
    gcdmap[pi(ab, bb)] = a;
    return a;
}
int main() {
    int t;
    int res;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--) {
        int n;
        int q;
        cin >> q;
        fr(k, q) {
            cin >> n;
            if(n == 1) {
                cout << "1\n";
                continue;
            }
            if(dp[n] != -1) {
                cout << dp[n] << " ";
                continue;
            }
            res = 0;
            int prev, curr;
            prev = gcd(n, 0);
            for(int i = 1; i < n; i++) {
                if((curr = gcd(n, i)) == 1) {
                    res += prev;
                }
                prev = curr;
            }
            dp[n] = res;
        printf("%d ", dp[n]);
        }
        printf("\n");
    }
    return 0;
}
