
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


pi canMeasure(vi &scale, int d) {
    for(int i = 0, l = scale.size(); i < l; i++) {
        vi::iterator loc = lower_bound(scale.begin() + i, scale.end(), d + scale[i]);
        if(loc != scale.end() && (scale[loc - scale.begin()] - scale[i] == d)) {
            return pi(i, loc - scale.begin());
        }
    }
    return pi(-1, -1);
}
int main() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vi scale(n, 0);
    scale.reserve(n + 2);
    for(int i = 0; i < n; i++) {
        cin >> scale[i];
    }
    pi bpair = canMeasure(scale, y);
    pi gpair = canMeasure(scale, x);
    bool bn = (bpair.first == -1);
    bool gn = (gpair.first == -1);
    if(bn && gn) {
        vi scaleboy(scale);
        //first insert boy's scale, then girl's
        vi::iterator loc = lower_bound(all(scale), y);
        //cout << loc - scale.begin();
        scale.insert(loc, y);
        /*
        for(int i = 0; i <= n; i++) {
            cout << scale[i] << " ";
        }
        cout << "\n";
        */
        if(canMeasure(scale, x).first != -1) {
            cout << "1\n" << y << "\n";
        } else {
            //also try girl and boy
            scale = scaleboy;
            vi::iterator loc = lower_bound(all(scale), x);
            scale.insert(loc, x);
            if(canMeasure(scale, y).first != -1) {
                cout << "1\n" << x << "\n";
            } else { //have to go with 2
                cout << "2\n" << x << " " << y << "\n";
            }
        }
        return 0;
    }
    if(bn) {
        cout << "1\n" << y << "\n";
    } else if(gn) {
        cout << "1\n" << x << "\n";
    } else {
        cout << "0\n";
    }
    return 0;
}
