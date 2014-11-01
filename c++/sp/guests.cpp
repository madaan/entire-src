//sg
#include<bits/stdc++.h>
using namespace std;
vector< int > adj[60];
vector< int > color(60, -1);
vector< int > degree(60, -1);
vector< bool > visited(60, false);
vector< bool > solved(60, false);
set<int> deleted;
int g;
void clr(int src) {
    int col = 0;
    queue<int> q;
    q.push(src);
    color[src] = 0;
    visited[src] = true;
    while(!q.empty()) {
        int curr = q.front();
        //cout << visited[1] << "\n";
        q.pop();
        //cout << q.size() << "\n";
        int cc = color[curr];
        //cout << "curr : " << curr << "col : " << cc << "\n";
        for(int i = 0, l = adj[curr].size(); i < l; i++) {
            //cout << curr << "-> " << adj[curr][i] << "\n";
            if( !visited[adj[curr][i]]) {
                q.push(adj[curr][i]);
                visited[adj[curr][i]] = true;
                solved[adj[curr][i]] = true;
                color[adj[curr][i]] = (cc == 1 ? 0 : 1);
                //cout << "col : " << adj[curr][i] << color[adj[curr][i]] << "\n";
            }
        }
    }
}

void del(int x) {
    adj[x].clear();
    deleted.insert(x);
}

void pluck(int a, int b) {
    del(a);
    del(b);
}
bool canpluck(int src) {
    for(int i = 0, l = adj[src].size(); i < l; i++) {
        if(color[src] != color[adj[src][i]]) {
            pluck(src, adj[src][i]);
            return true;
        }
    }
    return false;
}

int solve() {
    vector< pair<int, int> > degorder;
    //consider in sorted order
    for(int i = 1; i <= g; i++) {
        degorder.push_back(pair<int, int>(degree[i], i));
    }
    sort(degorder.begin(), degorder.end());
    int res = 0;
    for(int i = 0; i < g; i++) {
        if(deleted.find(degorder[i].second) == deleted.end() && canpluck(degorder[i].second)) {
            res += 2;
        }
    }
    return res;
}

int main() {
    string line[60];
    cin >> g;
    char c;
    for(int i = 1; i <= g; i++) {
        //cin >> line[i];
        for(int j = 1; j <= g; j++) {
            cin >> c;
            if(c == 'Y') {
                adj[i].push_back(j);
                degree[j]++;
            }
        }
    }
    
    for(int i = 1; i <= g; i++) {
        if(!solved[i]) {
            solved[i] = true;
            clr(i);
        }
    }

    /*
    color[1] = 0;
    for(int i = 1; i <= g; i++) {
        for(int j = 0, l = adj[i].size(); j < l; j++) {
            color[adj[i][j]] = color[i] == 1 ? 0 : 1;
        }
    }
    */

    for(int i = 1; i <= g; i++) {
     //   cout << i << " = " << color[i] << "\n";
    }
    
    cout << solve() << "\n";

    return 0;
}
