//sg
#include <list>
#include <queue>
#include <stdio.h>
using namespace std;
int adj[][4] = {
    {0, 0, 0, 0},
    {2, 3, 5, 9},
    {1, 4, 6, 10},
    {1, 4, 7, 11},
    {2, 3, 8, 12},
    {1, 13, 6, 7},
    {2, 5, 8, 14},
    {3, 5, 8, 15},
    {4, 6, 7, 16},
    {1, 10, 11, 13},
    {2, 9, 12, 14},
    {9, 12, 15, 3},
    {4, 11, 16, 10},
    {9, 14, 15, 5},
    {13, 6, 16, 10},
    {7, 13, 11, 16},
    {8, 14, 15, 12}
};
int state[17];
list<int> on_states;
int count_ones() {
    int num_ones = 0;
    for(int i = 1; i<= 8; i++) {
        if(state[i] == 1) {
            num_ones++;
            on_states.push_back(i);
        }
    }
    return num_ones;
}
//given a vertex which is 1, this function calculates
//the distance to nearest 0 node which is >= 8
//Clearly, all the nodes in the path should be 0
int find_distance(int source) {
    queue<int> q;
    int distance[17], curr;
    distance[source] = 0;
    q.push(source);
    int neigh;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            neigh = adj[curr][i];
            if(state[neigh] == 0) {
                distance[neigh] = distance[curr] + 1;
                if(neigh > 8) { //found
                    return distance[neigh];
                }
                if(distance[neigh] > 3) {
                    return distance[neigh];
                }
                q.push(neigh);
            }
        }
    }
    return 10;
}
int main() {
    int num_ones, total_dist = 0, cases;
    scanf("%d", &cases);
    for(int case_c = 1; case_c <= cases; case_c++) {
        printf("Case #%d: ", case_c);
        on_states.clear();
        total_dist = 0;
        num_ones = 0;
        for(int i = 1; i <= 16; i++) {
            scanf("%d", &state[i]);
        }
        num_ones = count_ones();
        for(int i = 1; i <= 16; i++) {
            //  printf("%d ", state[i]);
        }
        //printf("\n");
        if(num_ones > 3) {
            printf("more\n");
            continue;
        }
        for(list<int>::iterator  i = on_states.begin(); i != on_states.end(); i++) {
            //printf("%d\n", *i);
            total_dist += find_distance(*i);
            if(total_dist > 3) {
                break;
            }
        }
        if(total_dist > 3) {
            printf("more\n", total_dist);
        } else {
            printf("%d\n", total_dist);
        }
    }
    return 0;
}
