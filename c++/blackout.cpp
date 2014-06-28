//sg
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define MAX 2005
#define max(a, b) (a > b ? a : b)
#define ini(a, v)   memset(a, v, sizeof(a))
int cache[MAX][MAX];
int M, N, K, Q;
int caracas[MAX][MAX];
int caracasCumulative[MAX][MAX];
int areaZone[MAX];
int peopleZone[MAX];
vector<pi> areaPop;

/**
 * Can be improved to O(1)
 */
int getPeopleLiving(int i1, int j1, int i2, int j2) {
    return caracasCumulative[i2][j2] - caracasCumulative[i2][j1 - 1] - caracasCumulative[i1 - 1][j2] + caracasCumulative[i1 - 1][j1 - 1];
    
}

int maxArea(int i, int peopleLeft) {
    //printf("maxArea(%d, %d)\n", i, peopleLeft);
    if(peopleLeft <= 0 || i == Q) {
        return 0;
    }
    //two cases, take or don't take the current value
    int area = areaZone[i];
    int people = peopleZone[i];
    if(peopleLeft < people) {
        if(cache[i + 1][peopleLeft] == -1) {
            cache[i + 1][peopleLeft] = maxArea(i + 1, peopleLeft);
        }
        return cache[i + 1][peopleLeft];
    }
                
    if(cache[i + 1][peopleLeft - people] == -1) {
        cache[i + 1][peopleLeft - people] = maxArea(i + 1, peopleLeft - people);
    }
    if(cache[i + 1][peopleLeft] == -1) {
        cache[i + 1][peopleLeft] = maxArea(i + 1, peopleLeft);
    }
    return max(cache[i + 1][peopleLeft - people] + area, cache[i + 1][peopleLeft]);
}

int main() {
    memset(cache, -1, sizeof(cache[0][0]) * MAX * MAX);
    scanf("%d%d%d%d", &N, &M, &Q, &K);
    for(int i = 1; i <= N; i++) {
        int rowSum = 0;
        for(int j = 1; j <= M; j++) {
            scanf("%d", &caracas[i][j]);
            caracasCumulative[i][j] = caracasCumulative[i - 1][j] + rowSum + caracas[i][j];
            rowSum += caracas[i][j];
        }
    }
    int i1, i2, j1, j2;
    for(int i = 0; i < Q; i++) {
        scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
        areaZone[i] = (i2 - i1 + 1) * (j2 - j1 + 1);
        peopleZone[i] = getPeopleLiving(i1, j1, i2, j2);
    }
    printf("%d\n", maxArea(0, K));
    return 0;
}


