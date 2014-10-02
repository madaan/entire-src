
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

bool inorder_first(pstr &i, pstr &im1) {
    if((i.first > im1.first) || (i.second > im1.first)) {
        return true;
    }else if((i.first > im1.second) || (i.second > im1.second)) {
        im1.first.swap(im1.second);
        return true;
    }
    return false;
}

bool inorder(pstr &i, pstr &im1) {
    if((i.first > im1.first)) {
        return true;
    }else if((i.first > im1.second)) {
        im1.first.swap(im1.second);
        return true;
    }
    return false;
}


int main() {
    int n;
    vector< pstr > names;
    string fn, ln;
    cin >> n;
    names.pu(pstr(string(""), string("")));
    for(int i = 1; i <= n; i++) {
        cin >> fn >> ln;
        names.pu(pstr(fn, ln));
    }
    vi order(n + 5, 0);
    for(int i = 1; i <= n; i++) {
        cin >> order[i];
    }
    if(!inorder_first(names[order[n]], names[order[n - 1]])) {
            cout << "NO\n";
            return 0;
    }

    for(int i = n - 1; i >= 2; i--) {
        if(!inorder(names[order[i]], names[order[i - 1]])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

