//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< vector < int > > MAT;
typedef vector< vector < bool > > BMAT;
class elem
{
    public:
    int v;
    int x, y;
    elem() {
    }
    elem(int v, int x, int y) {
        this->v = v;
        this->x = x;
        this->y = y;
    }
    bool operator()(elem e1, elem e2) {
        return e1.v >= e2.v;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    MAT m(N, vector<int>(M, 0));
    BMAT vis(N, vector<bool>(M, false));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    int k;
    cin >> k;
    priority_queue<elem, vector<elem>, elem> pq;
    pq.push(elem(m[0][0], 0, 0));
    vis[0][0] = true;
    int num_pops = 0;
    elem min_elem;
    assert(k >= 1);
    while(!pq.empty() && num_pops < k) {
        min_elem = pq.top();
        pq.pop();
        num_pops++;
        int moves[2][2] = {{1, 0}, {0, 1}};
        for(int i = 0; i < 2; i++) {
            int dx = min_elem.x + moves[i][0];
            int dy = min_elem.y + moves[i][1];
            if(dx >= M || dy >= N || vis[dx][dy]) continue;
            pq.push(elem(m[dx][dy], dx, dy));
            vis[dx][dy] = true;
        }
    }
    cout << min_elem.v << "\n";
    return 0;
}
