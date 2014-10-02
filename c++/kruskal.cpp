#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

//route_weight stores weight of edge between u & v <weight, <u, v> >
typedef pair<int,pair<int,int> > route_weight; 
typedef priority_queue<route_weight, vector<route_weight>, greater<route_weight> > min_priority_queue;

void print_route(route_weight A);
vector<route_weight> MST_KRUSHAL(int N, min_priority_queue Q);

int main()
{
    int t;
    cin >> t;
    while(t--) {
    int N, E; //Graph with N vertices [1,N] and E edges 
    cin >>N >>E;

    int u, v, w;
    //Q is a minimum priority queue to store an edge (u->v) and its weight (w) as <w, <u,v> >
    min_priority_queue Q;  
    for (int i = 0; i < E; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        Q.push(make_pair(w, make_pair(u, v)));
    }

    vector<route_weight> mst_routes(MST_KRUSHAL(N, Q));
    int res = 0;
    for (int i = 0; i < mst_routes.size(); ++i)
    {
    res += mst_routes[i].first;
    }
    cout << res << "\n";
}
    return 0;
}

vector<route_weight> MST_KRUSHAL(int N, min_priority_queue Q)
{
    vector<route_weight> mst_routes;

    //Creating the disjoint set forest for each vertex. This stores information whether two nodes are connected by a path or not.
    map<int,int> connected;
    for (int i = 1; i <= N; ++i)
    {
        connected[i]=i;
    }

    while(!Q.empty())
    {
        int u = Q.top().second.first, v = Q.top().second.second, w = Q.top().first;
        //parent_x stores information about the set that x belongs to.
        int parent_u = connected[u], parent_v = connected[v]; 
        if(parent_u != parent_v) //if u and v are not connected by a path.
        {
            mst_routes.push_back(make_pair(w, make_pair(u, v)));
            for (int i = 1; i <= N; ++i) // UNION(u,v)
            {
                if(connected[i] == parent_v)
                {
                    connected[i] = parent_u;
                }
            }
        }
        Q.pop();
    }
    return mst_routes;
}
