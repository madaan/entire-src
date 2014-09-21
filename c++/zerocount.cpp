
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
    int n;
    cin >> n;
    string lets;
    fr(i, n)
        cin >> lets[i];
    int l = n;
    int nc = 0;
    int lc = 0;
    int i = 0;
    int sumc = 0;
    while(lets[i]) {
        if(lets[i] == '1') {
            lc = 1;
            nc++;
            i++;
            while(i < l && lets[i] == '1') {
                lc++;
                i++;
            }
            sumc += lc;
        } else {
            i++;
        }
    }
    if(nc == 0) 
        cout << "0\n";
    else 
        cout << sumc + nc - 1 << "\n";
    return 0;
}
