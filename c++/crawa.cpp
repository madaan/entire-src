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
int abs(int n) {
    return n > 0 ? n : -n;
}
const int oo = 2000000009;
const double eps = 1e-9;
#define rn return "NO"
#define ry return "YES"
const char *check(int x, int y) {
    if(x >= 0 && y >= 0) { //top half
        if(y % 2 == 0 && x < y) {
            ry;
        } else if(x % 2 != 0 && x >= y) {
            ry;
        }
    }
    if(x < 0 && y > 0) { //top half
        if(y % 2 == 0 && abs(x) <= y) {
            ry;
        } else if(x % 2 == 0 && y <= abs(x)) {
            ry;
        }
    }
    if(x < 0 && y < 0) {
        int ax = abs(x), ay = abs(y);
        if(ax % 2 == 0 && ay <= ax) {
            ry;
        } else if(ay % 2 == 0 && ax <= ay) {
            ry;
        }
    } else {
        if(y % 2 == 0 && x <= abs(y)) {
            ry;
        } else if(x % 2 != 0 && x > abs(y)) {
            ry;
        }
    }
    rn;
}
int main() {
    int t;
    int x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &x, &y);
        if(x == 0 && y == 0) {
            printf("YES\n");
            continue;
        }
        printf("%s\n", check(x, y));
    }
    return 0;
}
