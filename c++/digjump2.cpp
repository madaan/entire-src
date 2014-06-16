//sg
#include<vector>
#include<stdio.h>
#include<string.h>
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
    scanf("%s", ip);
    int l = strlen(ip);
    if(l == 1) {
        printf("0\n");
        return 0;
    }

    int curr = INT(ip[0]);
    min_val[curr] = 0;
    min_index[curr] = 0;

    for(int i = 1; i < l - 1; i++) {
        int curr = INT(ip[i]);
        int next = INT(ip[i + 1]);
        int prev = INT(ip[i - 1]);
        //what is the value that you are going to get?
        int next_val = (min_index[next] == i + 1) ? (min_val[next]) : (min_val[next] + 1);
        //int prev_val = (min_index[prev] == i - 1) ? (min_val[prev]) : (min_val[prev] + 1);
        int prev_val = path[prev];
        //for current, you will get the current minimum itself
        path[curr] = min(min_val[curr], min(next_val, prev_val)) + 1;

        if(path[curr] < min_val[curr]) {
            min_val[curr] = path[curr];
            min_index[curr] = i;
        }
    }
    curr = INT(ip[l - 1]);
    int prev = INT(ip[l - 2]);
    //int prev_val = (min_index[prev] == l - 2) ? (min_val[prev]) : (min_val[prev] + 1);
    int prev_val = path[prev];
    printf("%d\n", min(min_val[curr], prev_val) + 1);
    return 0;

}
