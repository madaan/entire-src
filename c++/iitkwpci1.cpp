//sg
#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define MAXN 1010
list<int> adj[MAXN];
int n, m;
typedef pair<int, int> pi;
vector<pi> connectedComps;
vector<bool> visited(MAXN, false);
vector<int> vn(MAXN, 0);
vector<int> smallestPerm(MAXN, 0);
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
void updatePerm() {
    if(smallestPerm.empty()) {
        return;
    }
    vector<int> indexes, values;
    tr(connectedComps, i) {
        int val = (*i).first;
        int index = (*i).second;
        values.push_back(val);
        indexes.push_back(index);
        //printf("val[%d] = %d\n", index, val);
    }
    sort(values.begin(), values.end());
    sort(indexes.begin(), indexes.end());
    for(int i = 0; i < values.size(); i++) {
        smallestPerm[indexes[i]] = values[i];
    }
}
void dfs(int i) {
    //printf("visiting %d\n", i);
    list<int>::iterator nbr = adj[i].begin();
    for(; nbr != adj[i].end(); nbr++) {
        if(!visited[*nbr]) {
            connectedComps.push_back(pi(vn[*nbr], *nbr));
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
            connectedComps.push_back(pi(vn[i], i));
            visited[i] = true;
            dfs(i);
        }
    }
    updatePerm();
}
int main() {
    int t;
    int temp, a, b;
    scanf("%d", &t);
    while(t--) {
        fill(visited.begin(), visited.end(), false);
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            scanf("%d", &temp);
            vn[i] = temp;
            smallestPerm[i] = temp;
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        drive();
        for(int i = 1; i <= n; i++) {
            printf("%d ", smallestPerm[i]);
        }
        printf("\n");
    }
    return 0;
}
=======
    vector<int> vertexValue;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            vertexValue[i] = temp;
            >>>>>>> 66dbee581d3557e9f5ceb7f68eca868605e08a05
