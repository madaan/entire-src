//sg
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pi;
#define MAXN 502
#define MAXM 10009
#define INF 100000000
#define UNDEF -1
int adj[MAXN][MAXN];
int distFrom[MAXN];
int distTo[MAXN];
int almostDist[MAXN];
int shortestPath;
void dijkstra(int key[], int src, bool transpose = false, bool ignoreEdges = false) {
    priority_queue<pi, vector<pi>, greater<pi> > Q;
    for(int i = 0; i < MAXN; i++) {
        key[i] = INF;
    }
    key[src] = 0;
    Q.push(pi(key[src], src));
    int edgeWeight = 0, currVertex = 0, currKey = 0;
    while(!Q.empty()) {
        pi curr = Q.top();
        Q.pop();
        currKey = curr.first;
        currVertex = curr.second;
        //printf("Popped : %d\n", currVertex);
        for(int i = 0; i < MAXN; i++) { //for all neighbors
            if(transpose) {
                edgeWeight = adj[i][currVertex];
            } else  {
                edgeWeight = adj[currVertex][i];
            }
            if(ignoreEdges && edgeWeight != UNDEF) {
                if(distTo[currVertex] + edgeWeight + distFrom[i] == shortestPath) {
                    continue;
                }
            }
            if(edgeWeight != UNDEF) {
                //printf("%d -> %d edgeWeight = %d key[i] = %d\n", currVertex, i, decisionValue, key[i]);
                if((key[currVertex] + edgeWeight) < key[i]) {
                    key[i] = key[currVertex] + edgeWeight;
                    Q.push(pi(key[i], i));
                    //printf("Pushed : %d\n", currVertex);
                }
            }
        }
    }
}
int main() {
    int N, M;
    int S, D;
    int U, V, P;
    while(true) {
        scanf("%d%d", &N, &M);
        if(N == 0) {
            return 0;
        }
        memset(adj, UNDEF, sizeof(adj[0][0]) * MAXN * MAXN);
        scanf("%d%d", &S, &D);
        for(int i = 0; i < M; i++) {
            scanf("%d%d%d", &U, &V, &P);
            adj[U][V] = P;
        }
        dijkstra(distTo, S); //apply dijkstra in front
        shortestPath = distTo[D];
        dijkstra(distFrom, D, true);
        dijkstra(almostDist, S, false, true);
        if(almostDist[D] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", almostDist[D]);
        }
    }
    return 0;
}
