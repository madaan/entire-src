//sg
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;
vector<int> adjacency[100005];
struct Component {
    int numElements;
};

Component component[100005];
char visited[100005];
stack<int> dfs;
void init()
{
    for (int i = 1; i < 100005 ; i++) {
        visited[i] = '0';
        adjacency[i].clear();
    }
    while (!dfs.empty()) {
        dfs.pop();
    }

}

int getPossibilityCount(int N)
{
    int result = 1;
    for (int i = 1; i <= N; i++) {
        result = ((result % (1000000007)) * ((component[i].numElements) % (1000000007))) % (1000000007);
    }
    return (result % 1000000007);
}

int main()
{
    int N, M;
    int a, b;
    int  temp;
    int componentNumber = 0;
    int componentElementCount = 0;
    int cases;
    scanf("%d", &cases);
    while (cases--) {

        //Initialize data structures for this case
        init();
        componentElementCount = 1;
        componentNumber = 1;
        //Initialization over


        scanf("%d%d", &N, &M);

        for (int i = 0; i < M; i++) {
            scanf("%d%d", &a, &b);
            if (a > b) {
                a = a + b;
                b = a - b;
                a = a - b;
            }
            adjacency[a].push_back(b);
            adjacency[b].push_back(a);
        }

        //now go through all the lists

        for (int i = 1; i <= N; i++) {

            //is the node already visited?
            if (visited[i] == '1') {
                continue;
            }

            //if it's not taken, run a dfs
            //push the source
            dfs.push(i);

            do {
                //pop
                temp = dfs.top();
                dfs.pop();
                visited[temp] = '1';
                for (vector<int>::iterator it = adjacency[temp].begin(); it != adjacency[temp].end(); ++it) {
                    //push all the unvisited nodes
                    if (visited[*it] == '0') {
                        componentElementCount++;
                        dfs.push(*it);
                        visited[*it] = '1';
                    }
                }
            } while (!dfs.empty());

            component[componentNumber].numElements = componentElementCount++;
            componentNumber++;
            componentElementCount = 1;
        }

        printf("%d %d\n", componentNumber - 1, getPossibilityCount(componentNumber - 1));

    }

    /*for(int i = 1;i <= N; i++) {
        printf("%d : ", i);
        for(vector<int>::iterator it = adjacency[i].begin(); it != adjacency[i].end(); ++it)
            {
            printf("%d -> ",*it);
            }
            printf("\n");
    }

    /**/
    return 0;

}
