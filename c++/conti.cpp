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
#define MAX 500009
int a[MAX];
vector<ll> cum;
int n;
int main() {
    cin >> n;
    cum.push_back(0);
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        //cin >> a[i];
        cum.push_back(cum[i - 1] + a[i]);
        //cout << cum[i] << " ";
    }
    if(cum[n] % 3 != 0) {
        cout << "0\n";
        return 0;
    } //cout << endl;
    double otd =  cum[n] / 3;
    double ttd = otd * 2;

    ll ot = otd;
    ll tt = ttd;
    vi tti, oti;
    ll otc = 0, ttc = 0;
    for(int i = n - 1; i >= 1; i--) {
        if(cum[i] == tt) {
            tti.push_back(i);
            ttc++;
        } else if(cum[i] == ot) {
            otc++;
            oti.push_back(i);
        }
    }
    sort(all(tti));
    sort(all(oti));
    if(cum[n] == 0) {
        cout << (ttc * (ttc - 1)) / 2 << endl;
    } else {
        ll res = 0;
        for(int i = 0; i < oti.size(); i++) {
            //cout << "finding " << oti[i] << endl;
            vi::iterator fo = upper_bound(tti.begin(), tti.end(), oti[i]);
            //cout << distance(fo, tti.end()) << "\n";
            res += distance(fo, tti.end());
        }
        cout << res << endl;
    }
    return 0;
}
