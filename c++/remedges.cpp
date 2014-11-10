//sg
#include<bits/stdc++.h>
using namespace std;
vector< int > adj[101];
int child[101];
int count(int node, int par) {
    for(int i = 0, l = adj[node].size(); i < l; i++) {
        int nbr = adj[node][i];
        if(nbr != par) {
            child[node] += count(nbr, node);
        }
    }
    child[node] += 1;
    return child[node];
}
int res(int node, int par) {
    int ans = 0;
    for(int i = 0, l = adj[node].size(); i < l; i++) {
        int nbr = adj[node][i];
        if(nbr != par && (child[nbr] % 2 == 0)) {
            ans++;
        }
        if(nbr != par)
            ans += res(nbr, node);
    }
    return ans;
}
int main() {
    int n, m;
    int a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    count(1, -1);
    cout << res(1, -1) << "\n";
    return 0;
}
