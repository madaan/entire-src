//sg
#include <list>
#include <stdio.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    bool *visited;
public:
    int total_vol;
    Graph(int V);
    void add_edge(int a, int b);
    int ret_max(int source);
};
Graph::Graph(int V)
{
    this -> V = V;
    total_vol = 0;
    adj = new list<int>[V];
    visited = new bool[V];
}
inline void Graph::add_edge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int Graph::ret_max(int source)
{
    visited[source] = 1;
    int neigh_count = 0;
    int child_area = 0;
    for(list<int>::iterator i = adj[source].begin(); i != adj[source].end(); i++) {
        if(!visited[*i]) {
            neigh_count++;
            child_area += ret_max(*i);
        }
    }
    if(neigh_count == 0) {
        total_vol += 1;
        return 1;
    } else {
        int res = child_area + neigh_count + 1;
        total_vol += res;
        return res;
    }
}
int main()
{
    Graph *g;
    int t, n, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        g = new Graph(n);
        for(int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            //printf("%d to %d\n", a, b);
            g->add_edge(a, b);
        }
        g->ret_max(0);
        printf("%d\n", g->total_vol);
        //delete g;
    }
    return 0;
}
