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
bool isPali(string input) {
    if(input.size() < 2) return false;
    return input == string(input.rbegin(), input.rend());
}
int main() {
    int t;
    cin >> t;
    string s;
    int res;
    fr(t1, t) {
        cin >> s;
        int l = s.size();
        res = 0;
        for(int i = 0; i < l; i++) {
            for(int j = i; j < l; j++) {
                //cout << "testing " << s.substr(i, j - i + 1) << "\n";
                if(isPali(s.substr(i, j - i + 1))) {
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
