//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
vector< int > adj[MAX];
typedef unsigned long long ll;
vector< bool > visited(MAX, false);
int n, I;
ll dfs(int src) {
    stack<int> st;
    ll elems = 0;
    visited[src] = true;
    st.push(src);
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        elems++;
        for(int i = 0, l = adj[curr].size(); i < l; i++) {
            int nbr = adj[curr][i];
            if(!visited[nbr]) {
                visited[nbr] = true;
                st.push(nbr);
            }
        }
    }
    return elems;
}

ll dfsdrive() {
    vector< ll > comps;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(adj[i].size() == 0) {
                visited[i] = true;
                comps.push_back(1);
            } else {
                comps.push_back(dfs(i));
            }
        }
    }
    ll res = 0;
    vector< ll > cumsize(comps.size() + 1, 0);
    cumsize[0] = comps[0];
    for(int i = 1, l = comps.size(); i < l; i++) {
        cumsize[i] = cumsize[i - 1] + comps[i];
    }
    for(int i = 0, l = comps.size(); i < l; i++) {
            res += (comps[i] * (cumsize[l - 1] - cumsize[i]));
    }
    return res;
}

int main() {
    int a, b;
    cin >> n >> I;
    for(int i = 0; i < I; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfsdrive() << "\n";

    return 0;
}
