//sg
#include<stdio.h>
#include<vector>
#include<set>
#include<list>
using namespace std;
class Graph
{
public:
    int n;
    list<int> *adj;
    vector<bool> visited;
    vector<int> degree;
    vector<bool> marked;
    Graph(int n) {
        this -> n = n;
        adj = new list<int>[n + 1];
        visited = vector<bool>(n + 1, false);
        degree = vector<int>(n + 1, 0);
        marked = vector<bool>(n + 1, false);
    }
    void addBiEdge(int a, int b) {
        adj[b].push_back(a);
        adj[a].push_back(b);
        degree[a]++;
        degree[b]++;
    }
    void dfs(int curr) {
        if(degree[curr] == 1) {
            //printf("returning for %d\n", curr);
            return;
        }
        list<int> adjS = adj[curr];
        for(list<int>::iterator i = adjS.begin(); i != adjS.end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                dfs(*i);
            }
            if(!marked[*i] && !marked[curr]) {
                marked[curr] = true;
            }
        }
    }
    int collect() {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            res = marked[i] ? res + 1 : res;
        }
        return res;
    }
};
int main() {
    int n, from, to, q;
    scanf("%d", &n);
    scanf("%d", &q);
    if(n == 1) {
        printf("%d\n", q);
        return 0;
    }
    if(n == 2) {
        printf("%d\n", q - 1);
        return 0;
    }
    Graph g(n);
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &from, &to);
        g.addBiEdge(from, to);
    }
    for(int i = 0; i < n; i++) {
        if(!g.visited[i]) {
            g.dfs(i);
        }
    }
    int vcsize = g.collect();
    int save = q - vcsize;
    if(save >= 0) {
        printf("%d\n", save);
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
