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
int A = 1;
int B = 2;
int opp(int x) {
    return (x == A) ? B : A;
}
int adj[210][210];
bool check2Col(int nodes) {
    int col[210];
    int visited[210];
    for(int i = 1; i <= nodes; i++) {
        col[i] = -1;
        visited[i] = 0;
    }
    col[1] = A;
    queue<int> bfs;
    bfs.push(1);
    while(!bfs.empty()) {
        int curr = bfs.front();
        visited[curr] = 1;
        bfs.pop();
        for(int i = 1; i <= nodes; i++) {
            if(adj[curr][i] && !visited[i]) {
                if(col[i] == -1) {
                    col[i] = opp(col[curr]);
                } else if(col[i] == col[curr]) {
                    return false;
                }
                bfs.push(i);
            }
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    string p1, p2;
    bool no = false;
    for(int qq = 1; qq <= t; qq++) {
        memset(adj, 0, sizeof(adj));
        printf("Case #%d: ", qq);
        int m;
        cin >> m;
        map<string, int> vmap;
        int p;
        int vn = 1;
        for(p = 1; p <= m; p++) {
            cin >> p1;
            cin >> p2;
            int g1 = vmap[p1];
            int g2 = vmap[p2];
            if(g1 == 0) {
                g1 = vn;
                vmap[p1] = vn++;
            }
            if(g2 == 0) {
                g2 = vn;
                vmap[p2] = vn++;
            }
            adj[g2][g1] = adj[g1][g2] = 1;
        }
        bool poss = check2Col(vn - 1);
        if(!poss) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}
