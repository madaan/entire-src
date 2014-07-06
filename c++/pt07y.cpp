//sg
#include<stdio.h>
#include<stack>
#include<vector>
#include<list>
using namespace std;
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
class Graph
{
    list<int> *adj;
    int n;
    vector<bool> visited;
    vector<int> parent;
    public:
    Graph(int n) {
        this -> n = n;
        adj = new list<int>[n + 1];
        parent = vector<int>(n + 1, -1);
        visited = vector<bool>(n + 1, false);
    }
    void addBiEdge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool isTree(int s) {
        stack<int> st;
        bool cycle = false;
        st.push(s);
        while(!st.empty()) {
            int curr = st.top();
            st.pop();
            //printf("\npop %d : ", curr);
            visited[curr] = true;
            tr(adj[curr], i) {
                //printf("%d ", *i);
                if(visited[*i] && parent[curr] != *i) {
                    //printf("found a cycle from %d -> %d\n", *i, curr);
                    return false;
                }
                if(parent[curr] != *i) {
                    parent[*i] = curr;
                }
                if(!visited[*i]) {
                    st.push(*i);
                }
            }
        }
        return true;
    }

    bool simpleDFS(int src, int par) {
        visited[src] = true;
        bool res = true;
        tr(adj[src], i) {
            if(*i != par && visited[*i]) {
                return false;
            }
            if(*i != par && !visited[*i]) {
                res = res && simpleDFS(*i, src);
            }
        }
        return res;
    }
    bool simpleDFSDriver() {
        bool res = true;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                res = res && simpleDFS(i, -1);
            }
        }
        return res;
    }
};

int main() {
    int n, m;
    int a, b;
    scanf("%d%d", &n, &m);
    Graph g(n);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g.addBiEdge(a, b);
    }
    printf("%s\n", g.simpleDFSDriver() ? "YES" : "NO");
    return 0;
}
