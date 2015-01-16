//sg
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define MAX 55
#define INF 10000000
char grid[MAX][MAX];
int key[MAX][MAX];
int visited[MAX][MAX];
int H, W;
int maxKey;
void checkAndPush(queue<pi> &Q, int i, int j, int c_i, int c_j, char desired_ele) {
    if(grid[i][j] == desired_ele && !visited[i][j]) {
        Q.push(pi(i,j));
        key[i][j] = key[c_i][c_j] + 1;
        //printf("Pushing : G(%d, %d) = %c\n", i, j, grid[i][j]);
        //printf("Key     : K(%d, %d) = %d\n", i, j, key[i][j]);
        if(key[i][j] > maxKey) {
            maxKey = key[i][j];
        }
        visited[i][j] = 1;
    }
}
//the pair signifies i, j
void bfs(int si, int sj) {
    queue<pi> Q;
    Q.push(pi(si, sj));
    key[si][sj] = 1;
    if(maxKey == 0) {
        maxKey = 1;
    }
    while(!Q.empty()) {
        pi curr = Q.front();
        Q.pop();
        int c_i = curr.first;
        int c_j = curr.second;
        char ele = grid[c_i][c_j];
        //printf("Popped : G(%d, %d) = %c\n", c_i, c_j, ele);
        char desired_ele = char(int(ele) + 1);
        if(c_j > 0) checkAndPush(Q, c_i, c_j - 1, c_i, c_j, desired_ele); //left
        if(c_j < W - 1) checkAndPush(Q, c_i, c_j + 1, c_i, c_j, desired_ele); //right
        if(c_i > 0) checkAndPush(Q, c_i - 1, c_j, c_i, c_j, desired_ele); //bottom
        if(c_i < H - 1) checkAndPush(Q, c_i + 1, c_j, c_i, c_j, desired_ele); //top
        if(c_j > 0 && c_i > 0) checkAndPush(Q, c_i - 1, c_j - 1, c_i, c_j, desired_ele); //top left
        if(c_j < W - 1 && c_i > 0) checkAndPush(Q, c_i - 1, c_j + 1, c_i, c_j, desired_ele); //top right
        if(c_i < H - 1 && c_j > 0) checkAndPush(Q, c_i + 1, c_j - 1, c_i, c_j, desired_ele); //left bottom
        if(c_i < H - 1 && c_j < W - 1) checkAndPush(Q, c_i + 1, c_j + 1, c_i, c_j, desired_ele); //right bottom
    }
}
int main() {
    int caseNumber = 1;
    while(true) {
        scanf("%d%d", &H, &W);
        if(H == 0 && W == 0) {
            break;
        }
        for(int i = 0; i < H; i++) {
            scanf("%s", grid[i]);
        }
        memset(key, 0, sizeof(key[0][0]) * MAX * MAX);
        memset(visited, 0, sizeof(visited[0][0]) * MAX * MAX);
        maxKey = 0;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(grid[i][j] == 'A') {
                    bfs(i, j);
                }
            }
        }
        printf("Case %d: %d\n", caseNumber++, maxKey);
    }
    return 0;
}
