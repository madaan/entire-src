//sg
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10009];
typedef pair<int , int> pi;
map<pi, int> wtmap;
map<string, int> vmap;
int vno;
map< int, int > selfies;
map<int, int> smap;
set<pi> edgeset;
//fills the graph
void processeq(string eq) {
    stringstream ss(eq);
    string a, b;
    int number;
    getline(ss, a, '+');
    getline(ss, b, '=');

    ss >> number;
    if(a == b) {
        //self loop
        if(vmap.find(a) == vmap.end()) {
            vmap[a] = vno++;
        }
        selfies[vmap[a]] = number / 2;
        return;
    }
    //cout << a << b << number << "\n";
    if(vmap.find(a) == vmap.end()) {
        vmap[a] = vno++;
        //cout << a << " = " << vno - 1 << "\n";
    }
    if(vmap.find(b) == vmap.end()) {
        vmap[b] = vno++;
        //cout << b << " = " << vno - 1 << "\n";
    }
    int an = vmap[a];
    int bn = vmap[b];
    if(edgeset.find(pi(an, bn)) == edgeset.end() && edgeset.find(pi(bn, an)) == edgeset.end()) {
        adj[an].push_back(bn);
        adj[bn].push_back(an);
        wtmap[pi(an, bn)] = number;
        wtmap[pi(bn, an)] = number;
        edgeset.insert(pi(an, bn));
        edgeset.insert(pi(bn, an));
    }
}

pi getsd(string eq) {
    //cout << "-> " << eq << "\n";
    stringstream ss(eq);
    string a, b;
    int number;
    getline(ss, a, '+');
    ss >> b;
    //cout << "a = " << a << "b = " << b << "\n";
    if(vmap.find(a) == vmap.end() || vmap.find(b) == vmap.end()) {
        return pi(-1, -1);
    }
    return pi(vmap[a], vmap[b]);
}

#define INF 1000000000
void findpath(int &pathLen, int &pathVal, int src, int dest) {
    queue<int> qq;
    vector< bool > visited(vno, false);
    vector< int > wt(vno, 0);
    vector< int > key(vno, INF);
    key[src] = 0;
    //cout << "From " << src << "to" << dest << "\n";
    
    qq.push(src);
    while(!qq.empty()) {
        int curr = qq.front();
        qq.pop();
        if(visited[curr]) continue;
        //cout << "Popped : " << curr << "\n";
        visited[curr] = true;
        
        for(int i = 0; i < adj[curr].size(); i++) {
            int nbr = adj[curr][i];
            //cout << "nbr : " << nbr << "\n";
            if(!visited[nbr]) {
                if((key[curr] + 1) % 2 !=0) {
                key[nbr] = min(key[nbr], key[curr] + 1);
                if(key[nbr] % 2 != 0) {
                    wt[nbr] = wtmap[pi(curr, nbr)] + wt[curr];
                } else {
                    wt[nbr] = wt[curr] - wtmap[pi(curr, nbr)];
                }
                qq.push(nbr);
                }
            }
        }
    }
    pathLen = key[dest];
    pathVal = wt[dest];
}


void self(int src) {
    queue<int> qq;
    vector< bool > visited(vno, false);
    vector< int > wt(vno, 0);
    vector< int > key(vno, INF);
    key[src] = 0;
    //cout << "From " << src << "to" << dest << "\n";
    
    qq.push(src);
    while(!qq.empty()) {
        int curr = qq.front();
        qq.pop();
        //cout << "Popped : " << curr << "\n";
        visited[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            int nbr = adj[curr][i];
            if(!visited[nbr]) {
                key[nbr] = key[curr] + 1;
                if(key[nbr] % 2 != 0) {
                    wt[nbr] = wtmap[pi(curr, nbr)] + wt[curr];
                } else {
                    wt[nbr] = wt[curr] - wtmap[pi(curr, nbr)];
                }
                qq.push(nbr);
            }
        }
    }
    for(int i = 0; i < vno; i++) {
        if(wt[i] != 0) {
            smap[i] = (key[i] % 2 == 0) ? wt[i] + selfies[src] : wt[i] - selfies[src];
        }
    }
}




int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d:\n", qq);
        int n;
        cin >> n;
        vmap.clear();
        wtmap.clear();
        selfies.clear();
        for(int i = 0; i < 10009; i++) {
            adj[i].clear();
        }

        string eqstring;
        for(int i = 0; i < n; i++) {
            cin >> eqstring;
            processeq(eqstring);
        }
        //graph is made;
        //first get done with the selfies
        for(map<int, int>::iterator i = selfies.begin(); i != selfies.end(); i++) {
            self(i->first);
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++) {
            cin >> eqstring;
            pi sd = getsd(eqstring);
            if(sd.first == -1) {
                continue;
            }
            if(sd.first == sd.second) {
                if(smap.find(sd.first) != smap.end()) {
                    cout << eqstring << "=" << smap[sd.first] << "\n";
                }
                continue;
            }
            int pl, pwt;
            findpath(pl, pwt, sd.first, sd.second);
            //cout << pl << "\n";
            if(pl % 2 != 0) {
                cout << eqstring << "=" << pwt << "\n";
            } else if(smap.find(sd.first) != smap.end() && smap.find(sd.second) != smap.end()) {
                cout << eqstring << "=" << smap[sd.first] + smap[sd.second] << "\n";
            }

        }
    }
    return 0;
}
