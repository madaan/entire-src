
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

int main() {
    vector<string> strings;
    string target, str;
    int n;
    cin >> n;
    fr(i, n) { cin >> str; strings.push_back(str);}
    cin >> target;
    int L = target.size();
    sort(all(strings));
    vector<int> dp(L + 1, L + 1);
    dp[0] = 0;
    for(int i = 0; i < L; i++) { //for a string of this size
        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
        int t = 0;
        for(int j = 0; j < n; j++) {
            if(strings[j].substr(0, i) == target.substr(0, i)) { //legal tab
                t++;
                if(strings[j].length() <= target.length() && target.substr(0, strings[j].length()) == strings[j]) { //should try this
                    dp[strings[j].length()] = min(dp[strings[j].length()], dp[i] + t);
                }
            }
        }
    }
    cout << dp[L] + 1 << "\n";
    return 0;
}
