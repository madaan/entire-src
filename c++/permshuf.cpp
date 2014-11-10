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
#define MAX 100009
#define bp 4
#define ep 5
int cbl[MAX];
int dperm[MAX];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        int l, r;
        int temp;
        memset(cbl, 0, sizeof(cbl));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            dperm[i] = temp;
        }
        vector<pi> prs;
        map<int, int> se;
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &l, &r);
            prs.pu(pi(l, r));
        }
        sort(prs.begin(), prs.end());
        for(int i = 0; i < m; i++) {
            l = prs[i].first;
            r = prs[i].second;
            if(l == r) {
                if(cbl[l] != bp)
                    cbl[l] = ep;
                continue;
            }

            int j;
            for(j = l; j <= r - 1; j++) {
                cbl[j] = bp;
            }
            if(cbl[j] != bp) {
                cbl[j] = ep;
            }
        }

        prs.clear();
        for(int i = 1; i <= n; i++) {
            if(cbl[i] != 0) {
                pi tmp;
                tmp.first = i;
                while(i <= n && cbl[i] != ep) {
                    i++;
                }
                tmp.second = i;
                //printf("Adding : %d %d\n", tmp.first, tmp.second);
                prs.pu(tmp);
            }
        }
        bool impossible = false;
        int npr = prs.size();
        for(int i = 0; i < npr; i++) {
            //printf("%d %d\n", prs[i].first, prs[i].second);
            sort(dperm + prs[i].first, dperm + prs[i].second + 1);
        }
        /*
        for(int i = 1; i <= n; i++) {
            if(cbl[i] == 0 && dperm[i] != i) {
                impossible = true;
                break;
            }
        }
        */
        for(int i = 1; i <= n; i++) {
            if(dperm[i] != i) {
                impossible = true;
                break;
            }
        }
        if(impossible) {
            printf("Impossible\n");
        } else {
            printf("Possible\n");
        }
    }
    return 0;
}
