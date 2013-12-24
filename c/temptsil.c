//sg
#include <stdio.h>
#include <math.h>
#define UNDEFINED -1
#define to_left(node) (node == 1 ? N : node - 1)
#define to_right(node) (node == N ? 1 : node + 1)

unsigned long long int cache[60][60];

int N, K, start, final;

int distance(int a, int b) {
   int temp =  (a > b  ? (a - b) : (b - a));
   return (temp < N - temp ? temp : N - temp);
}

unsigned long long int numpaths(int node, int steps) {
    if(cache[node][steps] != UNDEFINED) { 
        return cache[node][steps];
    }
    if(steps == 0) { 
        cache[node][steps] = (node == final ? 1 : 0);
        return cache[node][steps];
    }

    //rule out impossible paths
    if(distance(node, final) > steps) {
        cache[node][steps] = 0;
        return cache[node][steps];
    }
    cache[node][steps] = numpaths(to_left(node), steps - 1) + numpaths(to_right(node), steps - 1);
    return cache[node][steps];
}


int main() {
    int i, j;
    while(1) {
    scanf("%d%d", &N, &K);
    if(N == -1) { 
        break;
    }
    for(i = 0; i < 60; i++) {
        for(j = 0; j < 60; j++) { 
            cache[i][j] = UNDEFINED;
        }
    }

    scanf("%d%d", &start, &final);
    printf("%lld\n", numpaths(start, K));
    }
    return 0;
}
