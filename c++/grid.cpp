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
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        ll res = 0;
        char ln[1100];
        scanf("%d", &n);
        vector<int> rowLast(n + 1, 0);
        vector<int> colLast(n + 1, 0);
        for(int i  = 1; i <= n; i++) {
            scanf("%s", ln + 1);
            for(int j  = 1; j <= n; j++) {
                if(ln[j] == '#') {
                    if(rowLast[i] < j) {
                        rowLast[i] = j;
                    }
                    if(colLast[j] < i) {
                        colLast[j] = i;
                    }
                }
            }
        }
        /*
        for(int j = 1; j <= n; j++) {
            printf("rowlast[%d] = %d, collast[%d] = %d\n", j, rowLast[j], j, colLast[j]);
        }
        */
        for(int i = 1; i <= n; i++) {
            int lastRow = colLast[i];
            if(lastRow == n) continue;
            for(int j = lastRow + 1; j <= n; j++) {
                if(rowLast[j] < i) {
                    res++;
                }
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
