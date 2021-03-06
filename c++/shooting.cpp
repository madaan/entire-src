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
int grid[100][100];
#define L 1
#define E 2
#define M 3
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        char temp[100];
        vector<pi> ens;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%s", temp + 1);
            for(int j = 1; j <= m; j++) {
                if(temp[j] == 'E') {
                    grid[i][j] = E;
                } else if(temp[j] == 'L') {
                    grid[i][j] = L;
                    ens.pu(pi(i, j));
                } else {
                    grid[i][j] = M;
                }
            }
        }
        for(int i = 0; i < ens.size(); i++) {
            int r = ens[i].first;
            int c = ens[i].second;
            for(int j = 1; j <= m; j++) {
                if(grid[r][j] == E) {
                    grid[r][j] = M;
                }
            }
            for(int k = r; k >= 1; k--) {
                if(grid[k][c] == E) {
                    grid[k][c] = M;
                }
            }
        }
        bool imp = false;
        for(int i = 1; i <= n; i++) {
            int j;
            for(j = 1; j <= m; j++) {
                if(grid[i][j] == E) {
                    imp = true;
                    break;
                }
            }
            if(j <= m) {
                break;
            }
        }
        if(imp) {
            printf("Impossible\n");
        } else {
            printf("Possible\n");
        }
    }
    return 0;
}
