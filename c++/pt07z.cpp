//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 10009
vector<int> adj[MAX];
void bfs(int src, int &farthest_val, int &farthest_vert, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> bfsq;
    vector<int> key(n + 1, -1);
    bfsq.push(src);
    key[src] = 0;
    while(!bfsq.empty()) {
        int curr = bfsq.front();
        bfsq.pop();
        visited[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            if(!visited[adj[curr][i]]) {
                key[adj[curr][i]] = key[curr] + 1;
                bfsq.push(adj[curr][i]);
            }
        }
    }
    farthest_val = key[1];
    farthest_vert = 1;
    for(int i = 2; i <= n; i++) {
        if(key[i] > farthest_val) {
            farthest_val = key[i];
            farthest_vert = i;
        }
    }
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int farthest_val, farthest_vert, farthest_vert2;
    int ans;
    bfs(1, farthest_val, farthest_vert, n);
    bfs(farthest_vert, ans, farthest_vert2, n);
    printf("%d\n", ans);
    return 0;
}
