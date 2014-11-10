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
list<int> adj[MAX];
vector<int> connectedComps;
int n, m;
vector<bool> visited(MAX, false);
int cbl[MAX];
int dperm[MAX];
void updatePerm() {
    if(connectedComps.empty()) {
        return;
    }
    int l = connectedComps[0];
    int r = connectedComps[connectedComps.size() - 1];
    sort(dperm + l, dperm + r + 1);
}
void dfs(int i) {
    //printf("visiting %d\n", i);
    list<int>::iterator nbr = adj[i].begin();
    for(; nbr != adj[i].end(); nbr++) {
        if(!visited[*nbr]) {
            connectedComps.push_back(*nbr);
            visited[*nbr] = true;
            dfs(*nbr);
        }
    }
}
void drive() {
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            updatePerm();
            connectedComps.clear();
            connectedComps.push_back(i);
            visited[i] = true;
            dfs(i);
        }
    }
    updatePerm();
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        fill(visited.begin(), visited.end(), false);
        int l, r;
        int temp;
        memset(cbl, 0, sizeof(cbl));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            scanf("%d", &temp);
            dperm[i] = temp;
        }
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &l, &r);
            adj[l].pu(r);
            adj[r].pu(l);
        }
        drive();
        bool impossible = false;
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
