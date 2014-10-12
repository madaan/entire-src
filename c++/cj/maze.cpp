//sg
#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef vector< vector <int> >  MAT;
int n, m;
int P[200][200];
#define INF 10000000
/*
void setval(MAT &mat, pi coord, int val) {
    int i = coord.first;
    int j = coord.second;
    mat[i][j] = val;
}
*/
#define setval(A, B, C) A[B.first][B.second] = C
vector< pi > getvalnbrs(pi coord) {
    vector< pi > res;
    int i = coord.first;
    int j = coord.second;

    if(i > 0 && P[i - 1][j] != -1) {
        res.push_back(pi(i - 1, j));
    }
    if(i < n - 1 && P[i + 1][j] != -1) {
        res.push_back(pi(i + 1, j));
    }
    if(j > 0 &&  P[i][j - 1] != -1) {
        res.push_back(pi(i, j - 1));
    }
    if(j < m - 1 &&  P[i][j + 1] != -1) {
        res.push_back(pi(i, j + 1));
    }
    return res;
}

/*
int getval(pi coord, MAT &mat) {
    int i = coord.first;
    int j = coord.second;
    return mat[i][j];
}
*/

#define getval(A, B) B[A.first][A.second]


void disp(pi x) {
    cout << x.first << ", " << x.second << "\n";
}
bool equals(pi a, pi b) {
    return a.first == b.first && a.second == b.second;
}

void mazesolve(pi start, pi end) {
    queue<pi> st;
    MAT visited(n, vector < int > (m, 0));
    MAT key(n, vector < int > (m, INF));
    MAT wt(n, vector < int > (m, -1));
    MAT dist(n, vector < int > (m, INF));
    setval(key, start, 0);
    setval(dist, start, 0);
    setval(wt, start, P[start.first][start.second]);
    st.push(start);
    while(!st.empty()) {
        pi curr = st.front();
        //cout << "Popped : " << curr.first << ", " << curr.second << "\n";
        //cout << "visited : " << getval(curr, visited) << "\n";
        st.pop();
        if(equals(curr, end)) {
            break;
        }
        if(getval(curr, visited)) {
            continue;
        }
        setval(visited, curr, 1);
        
        vector< pi > nbrs = getvalnbrs(curr);
        int ckey = getval(curr, key);
        for(int i = 0; i < nbrs.size(); i++) {
            if(getval(nbrs[i], visited) == 0) {
                setval(key, nbrs[i], ckey + 1);
                st.push(nbrs[i]);
            } else if(getval(nbrs[i], key) ==  ckey - 1) {
                //cout << "fixing wt\n";
                int nbr_wt = getval(nbrs[i], wt) + P[curr.first][curr.second];
                setval(wt, curr, max(nbr_wt, getval(curr, wt)));
            }
        }
    }
    //done, now getval the nbrs of the final piece
    vector< pi > nbrs = getvalnbrs(end);
    int mindist = INF;
    int maxwt = -1;
    for(int i = 0; i < nbrs.size(); i++) {
        if(mindist == getval(nbrs[i], key)) {
            if(maxwt < getval(nbrs[i], wt)) {
                maxwt = getval(nbrs[i], wt);
            }
        } else if(mindist > getval(nbrs[i], key)) {
            mindist = getval(nbrs[i], key);
            maxwt = getval(nbrs[i], wt);
        }
    }
    if(mindist == INF) {
        cout << "Mission Impossible.\n";
    } else {
        cout << maxwt + P[end.first][end.second] << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        cin >> n >> m;
        int enx, eny, exx, exy;
        cin >> enx >> eny >> exx >> exy;
        pi start(enx, eny);
        pi end(exx, exy);
        //cout << start.first << " " << start.second << "\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &P[i][j]);
            }
        }
        mazesolve(start, end);
    }
    return 0;
}
