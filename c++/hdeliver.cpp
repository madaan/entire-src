//sg
#include <stdio.h>
bool graph[100][100];
int main()
{
    int N, M, Q, a, b, T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                if(i != j) {
                    graph[i][j] = false;
                } else {
                    graph[i][j] = true;
                }
            }
        }
        while(M--) {
            scanf("%d%d", &a, &b);
            graph[a][b] = graph[b][a] =  true;
        }
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                }
            }
        }
        scanf("%d", &Q);
        while(Q--) {
            scanf("%d%d", &a, &b);
            if(graph[a][b]) {
                printf("YO\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
