//sg
#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define num(i, j) i * M + j
#define INF 10000000
#define abs(a, b) (a > b ? (a - b) : (b - a))
#define min(a, b) (a < b ? a : b)
typedef pair<int, pair<int, int> > key_vertex;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
char graph[55][55];
//returns the distances from the X to all the $s.
//Basically uses dijkstra to achieve this.
int getEdgeWeight(int fi, int fj, int ti, int tj) {
    char from = graph[fi][fj];
    char to = graph[ti][tj];
    //printf("from = %c, to = %c\n", from, to);
    if(from >= '0' && from <= '9') { //empty space
        if(to >= '0' && to <= '9') { //to empty space
            int fromI = from - 48;
            int toI = to - 48;
            if(abs(fromI, toI) > 1) {
                return INF;
            }
            if(abs(fromI, toI) == 1) {
                return 3;
            }
            if(abs(fromI, toI) == 0) {
                return 1;
            }
        } else { //to building
            return 2;
        }
    } else { //building
        return 2;
    }
}
class VertexComparison {
public:
    bool operator() (key_vertex k1, key_vertex k2) {
        return k1.first > k2.first;
    }
};
int D[55][55]; //the total distance required for the dijkstra
int N, M;
priority_queue<key_vertex, vector<key_vertex>, VertexComparison > Q;
void relax(int i1, int j1, int i2, int j2) {
    if(i2 < 0 || j2 < 0 || i2 > M - 1 || j2 > N - 1) {
        return;
    }
    //printf("Testing : (%d, %d)\n", i2, j2);
    //printf("D[%d][%d] = %d\n", i2, j2, D[i2][j2]);
    //printf("D[%d][%d] = %d\n", i1, j1, D[i1][j1]);
    int ewt = getEdgeWeight(i1, j1, i2, j2);
    if(D[i2][j2] > D[i1][j1] + ewt) {
        D[i2][j2] = D[i1][j1] + ewt;
        Q.push(key_vertex(D[i2][j2], ii(i2, j2)));
        //printf("Pushed : (%d, %d)\n", i2, j2);
        //printf("Updated D[%d][%d] = %d\n", i2, j2, D[i2][j2]);
    }
}
vector<int> getDistances() {
    int srcJ, srcI;
    //fill in the edge weights
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == 'X') {
                srcI = i;
                srcJ = j;
            }
            D[i][j] = INF;
        }
    }
    Q.push(key_vertex(0, ii(srcI, srcJ)));
    D[srcI][srcJ] = 0;
    while(!Q.empty()) {
        key_vertex currBest = Q.top();
        Q.pop();
        //extract information about the current best vertex
        int cumDist = currBest.first;
        ii coord = currBest.second;
        int i = coord.first;
        int j = coord.second;
        //there can only be 4 adjacent vertices, test them all
        relax(i, j, i - 1, j); //top
        relax(i, j, i, j - 1); //left
        relax(i, j, i + 1, j); //bottom
        relax(i, j, i, j + 1); //right
    }
    vi res;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == '$') {
                res.pb(D[i][j]);
            }
        }
    }
    return res;
}
class BestPartition {
    vi distances;
    vi assignment;
    vi bestAssignment;
    int currBestFinishTime;
    int cumuA, cumuB;
    int lastA, lastB;
    vi A, B;
public:
    BestPartition(vi& distances) {
        this->distances.assign(all(distances));
        for(int i = 0; i < distances.size(); i++) {
            assignment.pb(0);
            bestAssignment.pb(0);
        }
        currBestFinishTime = INF;
        cumuB = cumuA = 0;
        lastB = lastA = 0;
    }
    int getClusterDiff() {
        vi delA, delB;
        int sumA = 0, sumB = 0;
        for(int i = 0; i < assignment.size(); i++) {
            if(assignment[i] == 0) {
                delA.pb(distances[i]);
            } else {
                delB.pb(distances[i]);
            }
        }
        tr(delA, i) {
            sumA += (*i);
        }
        tr(delB, i) {
            sumB += (*i);
        }
        return abs(sumA, sumB);
    }
    void findBestAssignment(int i) {
        if(i == distances.size()) {
            lastA = A.empty() ? 0 : A.back();
            lastB = B.empty() ? 0 : B.back();
            int finishTime = max(cumuA - lastA, cumuB - lastB);
            if(finishTime < currBestFinishTime) {
                currBestFinishTime = finishTime;
            }
            return;
        }
        assignment[i] = 0;
        cumuA += (distances[i] * 2);
        A.pb(distances[i]);
        findBestAssignment(i + 1);
        A.pop_back();
        cumuA -= (distances[i] * 2);
        assignment[i] = 1;
        cumuB += (distances[i] * 2);
        B.pb(distances[i]);
        findBestAssignment(i + 1);
        B.pop_back();
        cumuB -= (distances[i] * 2);
    }
    int getBestAssignmentCost() {
        findBestAssignment(0);
        return currBestFinishTime;
    }
};
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &M, &N);
        for(int i = 0; i < M; i++) {
            scanf("%s", graph[i]);
        }
        vi res = getDistances();
        sort(all(res));
        if(res.size() == 0) {
            printf("0\n");
        } else if(res.size() == 1) {
            printf("%d\n", res[0]);
        } else if(find(all(res), INF) != res.end()) {
            printf("-1\n");
        } else {
            BestPartition bp(res);
            printf("%d\n", bp.getBestAssignmentCost());
        }
    }
    return 0;
}
