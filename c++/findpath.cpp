//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 2500
#define INF 100000000
int adj[MAX][MAX];
int n, m, V;
int vn(int i, int j) {
    return j + (i - 1) * m;
}

void ap() {
    for(int k = 1; k <= V; k++) {
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                if((i != j) && (adj[i][j] > adj[i][k] + adj[k][j])) {
                adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}
                    
void disp() {
for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    cin >> n >> m;
    V = n * m;
    char hori[MAX],  vert[MAX];
    scanf("%s", hori + 1);
    scanf("%s", vert + 1);
    //fill mat rows
    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            adj[i][j] = INF;
        }
        adj[i][i] = 0;
    }

    for(int i = 1; i <= n; i++) {
            for(int j = 1; j < m; j++) {
                if(hori[i] == '>') {
                    adj[vn(i, j)][vn(i, j+ 1)] = 1;
                } else {
                    adj[vn(i, j + 1)][vn(i, j)] = 1;
                }
            }
    }

    //fill mat cols
    for(int j = 1; j <= m; j++) {
            for(int i = 1; i < n; i++) {
                if(vert[j] == 'v') {
                    adj[vn(i, j)][vn(i + 1, j)] = 1;
                } else {
                    adj[vn(i + 1, j)][vn(i, j)] = 1;
                }
            }
    }

    ap();
    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            if(adj[i][j] == INF) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
