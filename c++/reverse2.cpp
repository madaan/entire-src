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
#define INF 1000000000
#define MAX 100009
set<pi> edges;
set<int> adj[MAX];
bool visited[MAX];
int n, m;
int key[MAX];
map<pi, int> wtMap;
void dijkstra(int src) {
    priority_queue<pi, vector<pi>, greater<pi> > Q;
    for(int i = 0; i < MAX; i++) {
        key[i] = INF;
    }
    key[src] = 0;
    Q.push(pi(key[src], src));
    int edgeWeight = 0, currVertex = 0, currKey = 0, wt, newDist;
    while(!Q.empty()) {
        pi curr = Q.top();
        Q.pop();
        currKey = curr.first;
        currVertex = curr.second;

        tr(adj[currVertex], i) {
            if(edges.find(pi(currVertex, *i)) == edges.end()) {
                wt = 1;
            } else {
                wt = 0;
            }
            newDist = wt + key[currVertex];
            //relax all
            if(newDist < key[*i]) {
                key[*i] = newDist;
                Q.push(pi(newDist, *i));
            }
        }
    }
}
int main() {
    int x, y;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        if(x == y) {
            continue;
        }
        adj[x].insert(y);
        adj[y].insert(x);
        edges.insert(pi(x, y));
    }
    dijkstra(1);
    if(key[n] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", key[n]);
    }
    return 0;
}
