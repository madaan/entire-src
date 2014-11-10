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
#define MAX 2009
list<int> adj[MAX];
int adjMat[MAX][MAX];
int dist[MAX][MAX];
int visited[MAX][MAX];
ll res = 0;
int flag[MAX];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s][s] = 0;
    visited[s][s] = 1;
    while(!q.empty()) {
        int ele = q.front();
        q.pop();
        int cdis = dist[s][ele];
        if(cdis == 2 && adjMat[s][ele] != 1) {
            flag[ele] = 1;
            res++;
        }
        if(cdis >= 2) { //no point in exploring further, need only close friends
            continue;
        }

        tr(adj[ele], i) {
            //printf("%d ", *i);
            if(visited[s][*i] == 0) {
                dist[s][*i] = cdis + 1;
                visited[s][*i] = 1;
                q.push(*i);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    char vertLine[MAX];
    for(int i = 1; i <= n; i++) {
        scanf("%s", vertLine + 1);
        int j = 1;
        while(vertLine[j]) {
            if(vertLine[j] == '1') {
                adj[i].push_back(j);
                adjMat[i][j] = 1;
            }
            j++;
        }
    }
    for(int i = 1; i <= n; i++) {
        //apply bfs one by one
        //printf("Starting from %d\n", i);
        bfs(i);
        //count
        /*
        for(int j = 1; j <= n; j++) {
            //printf("dist(%d -> %d) = %d\n", i, j, dist[j]);
            if(dist[i][j] == 2 && adjMat[i][j] != 1) {
                res++;
            }
        }
        */
        //printf("got : %lld\n", res);
        //memset(dist, 0, sizeof(dist[0]) * MAX);
        //memset(visited, 0, sizeof(visited[0]) * MAX);
    }
    printf("%lld\n", res);
    return 0;
}
