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
typedef pair<string, string> pstr;
const int oo = 2000000009;
const double eps = 1e-9;

vector< pstr > names;

int dp[100009][3];
vi order;
int n;

void solve(int n) {
        if(names[order[2]].first > names[order[1]].first || names[order[2]].first > names[order[1]].second) {
            dp[2][0] = 1;
        }
        if(names[order[2]].second > names[order[1]].first || names[order[2]].second > names[order[1]].second) {
            dp[2][1] = 1;
        }
    for(int i = 3; i <= n; i++) {
    if(dp[i - 1][0]) {
        if(names[order[i]].first > names[order[i - 1]].first) {
            dp[i][0] = 1;
        }
        if(names[order[i]].second > names[order[i - 1]].first) {
            dp[i][1] = 1;
        }
    }
    if(dp[i - 1][1]) {
        if(names[order[i]].first > names[order[i - 1]].second) {
            dp[i][0] = 1;
        }
        if(names[order[i]].second > names[order[i - 1]].second) {
            dp[i][1] = 1;
        }
    }
    }
}
         


int main() {
    string fn, ln;
    cin >> n;
    names.pu(pstr(string(""), string("")));
    for(int i = 1; i <= n; i++) {
        cin >> fn >> ln;
        names.pu(pstr(fn, ln));
    }
    int tmp;
    order.pu(-1);
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        order.pu(tmp);
    }
    if(n == 1) {
        cout << "YES\n";
        return 0;
    }
    solve(n);
    if(dp[n][0] || dp[n][1] || (n == 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
