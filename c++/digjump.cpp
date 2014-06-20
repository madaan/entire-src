//sg
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>
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
char ip[MAX];
priority_queue<ii, vector<ii>, greater<ii> > Q;
vi key(MAX, INF);
void relax(int curr, int nbr) {
    if(key[curr] + 1 < key[nbr]) {
        key[nbr] = key[curr] + 1;
        //printf("Pushing %d with key %d\n", nbr, key[nbr]);
        Q.push(ii(key[nbr], nbr));
    }
}

char *compress(int l, int& nl) {
    char *nip = new char[l + 1];
    int i = 2;
    char p2 = ip[0];
    char p1 = ip[1];
    nip[0] = p2;
    nip[1] = p1;
    int j = 2;
    while(ip[i]) {
        if(ip[i] == p1 && p1 == p2) {
            while(ip[i] && ip[i] == p1) {
                p2 = p1;
                p1 = ip[i];
                i++;
            }
            if(ip[i] == '\0') {
                nip[j] = '\0';
                nl = j;
                return nip;
            }
        }
            nip[j] = ip[i];
            p2 = p1;
            p1 = ip[i];
            i++;
            j++;
        }
    nip[j] = '\0';
    nl = j;
    return nip;
}




int main() {
    scanf("%s", ip);
    int l = strlen(ip);
    //Manually check if this is an easy case
    if(l == 1) {
        printf("0\n");
        return 0;
    }
    if(ip[0] == ip[l - 1]) {
        printf("1\n");
        return 0;
    }
    if(ip[1] == ip[l - 1]) {
        printf("2\n");
        return 0;
    }
    if(ip[0] == ip[l - 2]) {
        printf("2\n");
        return 0;
    }
    
    vvi adj(10);
    //compress input to reduce all runnings of greater than 2
    int nl;
    char *nip = compress(l, nl);
    l = nl;
    int i = 0;
    while(nip[i]) {
        adj[INT(nip[i])].pb(i);
        i++;
    }
    Q.push(ii(0, 0));
    key[0] = 0;

    while(!Q.empty()) {
        ii top_element = Q.top();
        Q.pop();
        int dist = top_element.first;
        int vert = top_element.second;
        //printf("Popped : (Key : %d, Vert : %d)\n", dist, vert);
        tr(adj[INT(nip[vert])], nbr) {
            //printf("%d -> %d\n", vert, *nbr);
            relax(vert, (*nbr));
        }
        if(vert > 0) {
            relax(vert, vert - 1);
        }
        if(vert < l - 1) {
            relax(vert, vert + 1);
        }
        //printf("Q size : %d\n", (int)Q.size());
    }
    printf("%d\n", key[l - 1]);
    return 0;
}
