//sg
#include<stdio.h>
#include<string.h>
#define min(a, b) ((a < b) ? a : b)
#define MAX 105
#define UNDEF -1
#define INF 1000000000
int path[MAX][MAX];
int adj[MAX][MAX];
void floydWarshall(int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
}
int main() {
    int t;
    int n, a, b;
    scanf("%d", &t);
    int caseNumber = 1;
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = INF;
                path[i][j] = INF;
            }
        }
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            adj[a][b] = 1;
            path[a][b] = 1;
        }
        int closureCost = 0;
        floydWarshall(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                //printf("%d ", path[i][j]);
                if(adj[i][j] == INF && path[i][j] != INF) {
                    closureCost++;
                }
            }
            //printf("\n");
        }
        printf("Case #%d: %d\n", caseNumber++, closureCost);
    }
    return 0;
}
