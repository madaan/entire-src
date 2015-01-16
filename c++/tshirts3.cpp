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
#define MOD 1000000007
const int oo = 2000000009;
const double eps = 1e-9;
int toint(const string &s) {
    stringstream ss;
    ss << s;
    int x;
    ss >> x;
    return x;
}
ll dp[1030][110];
vector<int> owners[110]; //stores people who have t shirt i
int n, allset;
ll ways(int mask, int nextT) {
    //printf("ways(%d, %d)\n", mask, nextT);
    ll ans = 0;
    if(nextT == 101) {
        if(mask == allset) {
            //printf("here");
            return dp[mask][nextT] = 1ll;
        } else {
            return dp[mask][nextT] = 0ll;
        }
    }
    if(dp[mask][nextT] != -1) {
        return dp[mask][nextT];
    }
    ans += ways(mask, nextT + 1);
    int numOwners = owners[nextT].size(), i;
    for(i = 0; i < numOwners; i++) {
        int test = owners[nextT][i];
        if((mask) & (1 << test)) continue; //this guy already has a shirt
        ans += ways(mask | (1 << test), nextT + 1);
        //printf("ans way(%d, %d) = %lld\n", (mask | (1 << test)), nextT + 1,  ans);
        if(ans >= MOD)
            ans -= MOD;
    }
    return dp[mask][nextT] = ans;
}
int main() {
    int k, t;
    string ss, temp;
    scanf("%d", &t);
    while(t--) {
        for(int i = 1; i <= 100; i++) {
            owners[i].clear();
        }
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        cin.ignore();
        allset = (1 << n) - 1;
        //printf("%d\n", allset);
        for(int i = 0; i < n; i++) {
            getline(cin, ss);
            //cout << ss << endl;
            stringstream s (ss);
            while(s >> temp) {
                owners[toint(temp)].push_back(i);
            }
        }
        for(int i=1; i<=100; i++)
            sort(owners[i].begin(), owners[i].end());
        printf("%lld\n", ways(0, 1));
    }
    return 0;
}
