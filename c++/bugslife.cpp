//sg
#include<bits/stdc++.h>
using namespace std;
int n;

bool valid(int src, vector<int> adj[]) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> color(n + 1, false);
    for(int i = 1; i <= n; i++) if(!visited[i]) {
    color[i] = 1;
    visited[i] = true;
    q.push(i);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int i = 0, l = adj[curr].size(); i < l; i++) {
            if(!visited[adj[curr][i]]) {
                visited[adj[curr][i]] = true;
                color[adj[curr][i]] = (color[curr] == 0 ? 1 : 0);
                q.push(adj[curr][i]);
            } else if(color[adj[curr][i]] == color[curr]) {
                return false;
            }
        }
    }
    }
    return true;
}

int main() {
    int t;
    int a, b, e; 
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Scenario #%d:\n", qq);
        vector<int> adj[2005];
        cin >> n;
        cin >> e;
        for(int i = 1; i <= e; i++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("%s\n", valid(1, adj) ? "No suspicious bugs found!" : "Suspicious bugs found!");
    }
    return 0;
}
