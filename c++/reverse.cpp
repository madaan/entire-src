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
set<int> adj[MAX];
bool visited[MAX];
set<pair<int, int> > edgeSet;
vector<int> path;
int n, m;
int minFlips = oo;
void updateMinFlips() {
    int pathLen = path.size();
    int flips = 0;
    for(int i = 0; i < pathLen - 1; i++) {
        pair<int, int> edge(path[i], path[i + 1]);
        if(edgeSet.find(edge) == edgeSet.end()) {
            //printf("missing : (%d, %d)\n", edge.st, edge.se);
            flips++;
        }
    }
    if(flips < minFlips) {
        minFlips = flips;
    }
}
void dfs(int s) {
    //printf("here for %d\n", s);
    path.pu(s);
    if(s == n) { //reached our destination
        /*
        tr(path, i) {
            printf("%d ", *i);
        }
        printf("\n");
        */
        updateMinFlips();
        path.pop_back();
        return;
    }
    tr(adj[s], i) {
        //printf("%d -> %d\n", s, *i);
        if(!visited[*i] || *i == n) {
            visited[*i] = true;
            dfs(*i);
        }
    }
    path.pop_back();
}
int main() {
    int x, y;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        edgeSet.insert(pair<int, int>(x, y));
        adj[x].insert(y);
        adj[y].insert(x);
    }
    visited[1] = true;
    dfs(1);
    if(!visited[n]) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", minFlips);
    return 0;
}
