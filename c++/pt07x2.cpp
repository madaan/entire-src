//sg
#include<stdio.h>
#include<list>
using namespace std;
#define MAX 100009
int vc[MAX];
list<int> adj[MAX];
int degree[MAX];
bool visited[MAX];
#define UNDEF -1
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
int getvc(int r, int par) {
    //printf("getvc(%d)\n", r);
    if(vc[r] != UNDEF) {
        return vc[r];
    }
    //DP -> Either select the parent
    //You are not in the cover
    int notSelected = 0;
    int numChild = 0;
    tr(adj[r], i) { //for all adj
        if(*i != par) {
            numChild++;
            tr(adj[*i], j) { //for all grandchildren
                if(*j != r && *j != *i) { //for all children
                //printf("here child : %d, gc : %d\n", *i, *j);
                notSelected += getvc(*j, *i);
            }
        }
    }
    }
    notSelected += numChild;

    int selected = 1;
    //you are selected, your children may/not be
    tr(adj[r], i) { //for all adj
        if(*i != par) { //for all children
            selected += getvc(*i, r);
        }
    }
    vc[r] = min(selected, notSelected);
    return vc[r];
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        vc[i + 1] = UNDEF;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    vc[n] = UNDEF;
    printf("%d\n", getvc(1, -1));
    return 0;
}
