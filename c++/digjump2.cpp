//sg
#include<vector>
#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 100009
#define INF 10000000
#define INT(c) (c - '0')
#define ini(a, v)   memset(a, v, sizeof(a))
#define min(a, b) (a < b ? a : b)
char ip[MAX];
vi min_index(10); //stores the index of min value of i
vi path(MAX); //path length till i
int main() {
    vi min_val(10, INF); //stores the min value of i
    set<int> neighbors[10];
    scanf("%s", ip);
    int l = strlen(ip);
    if(l == 1) {
        printf("0\n");
        return 0;
    }
    neighbors[INT(ip[0])].insert(INT(ip[1]));
    for(int i = 1; ip[i + 1]; i++) {
        neighbors[INT(ip[i])].insert(INT(ip[i - 1]));
        neighbors[INT(ip[i])].insert(INT(ip[i + 1]));
    }
    neighbors[INT(ip[l - 1])].insert(INT(ip[l - 2]));
    int curr = INT(ip[0]);
    min_val[curr] = 0;
    min_index[curr] = 0;
    path[0] = 0;
    for(int i = 1; i < l - 1; i++) {
        int curr = INT(ip[i]);
        int next = INT(ip[i + 1]);
        int prev = INT(ip[i - 1]);
        //what is the value that you are going to get?
        int next_val = (min_index[next] == i + 1) ? (min_val[next]) : (min_val[next] + 1);
        //int prev_val = (min_index[prev] == i - 1) ? (min_val[prev]) : (min_val[prev] + 1);
        int prev_val = path[i - 1];
        //for current, you will get the current minimum itself
        path[i] = min(min_val[curr], min(next_val, prev_val)) + 1;
        //printf("At %d (%d), prev = %d, next = %d, curr = %d\n", i, curr, prev_val, next_val, min_val[curr]);
        if(path[i] < min_val[curr]) {
            //printf("%d %d\n", min_val[curr], path[i]);
            min_val[curr] = path[i];
            min_index[curr] = i;
            //also update all the neighbors
            //tr(neighbors[INT(ip[i])], iter)
            for(set<int>::iterator it = neighbors[INT(ip[i])].begin(); it != neighbors[INT(ip[i])].end(); it++) {
                if(min_val[curr] + 2 < min_val[*it]) {
                    min_val[*it] = min_val[curr] + 2;
                }
            }
            //now check for immediate neighbors
            if(min_val[prev] > min_val[curr] + 1) {
                min_val[prev] = min_val[curr] + 1;
                min_index[prev] = i - 1;
            }
            if(min_val[next] > min_val[curr] + 1) {
                min_val[next] = min_val[curr] + 1;
                min_index[next] = i + 1;
            }
        }
    }
    curr = INT(ip[l - 1]);
    int prev = INT(ip[l - 2]);
    //int prev_val = (min_index[prev] == l - 2) ? (min_val[prev]) : (min_val[prev] + 1);
    int prev_val = path[l - 2];
    path[l - 1] = min(min_val[curr], prev_val) + 1;
    /*printf("At %d (%d), prev = %d, curr = %d\n", l - 1, curr, prev_val, min_val[curr]);
    for(int i = 0; i < 10; i++) {
        printf("min(%d) = %2d\n", i, min_val[i]);
    }
    printf("\n");
    for(int i = 0; i < l; i++) {
        printf("path(%c) = %2d\n", ip[i], path[i]);
    }
    printf("\n");
    */
    printf("%d\n", path[l - 1]);
    return 0;
}
