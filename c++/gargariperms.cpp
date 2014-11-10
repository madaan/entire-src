//sg
#include<bits/stdc++.h>
#define MAX 1100
using namespace std;
int pos[10][MAX];
bool visited[MAX];
int key[MAX];
vector<int> adj[MAX];
int ans;
void dfs(int s) {
    visited[s] = true;
    //printf("%d\n", s);
    for(int i = 0; i < adj[s].size(); i++) {
        if(!visited[adj[s][i]]) {
            dfs(adj[s][i]);
        }
        key[s] = max(key[adj[s][i]] + 1, key[s]);
    }
    key[s] = max(key[s], 1);
    ans = max(ans, key[s]);
    //printf("%d\n", s);
}
void dfsmin(int s) {
    visited[s] = true;
    //printf("%d\n", s);
    for(int i = 0; i < adj[s].size(); i++) {
        key[adj[s][i]] = min(key[s] + 1, key[adj[s][i]]);
        if(!visited[adj[s][i]]) {
            dfs(adj[s][i]);
        }
        key[adj[s][i]] = min(key[s] + 1, key[adj[s][i]]);
        ans = min(ans, adj[s][i]);
    }
    //printf("%d\n", s);
}
#define INF 100000
int main() {
    int n, k;
    int temp;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <=n; j++) {
            scanf("%d", &temp);
            pos[i][temp] = j;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            bool alwaysBehind = true;
            for(int np = 1; np <= k; np++) {
                if(pos[np][i] >= pos[np][j]) {
                    alwaysBehind = false;
                }
            }
            if(alwaysBehind) {
                adj[i].push_back(j);
            }
        }
    }
    for(int i = n; i >= 1; i--) {

        if(!visited[i])  {
            key[i] = 0;
            dfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
