//sg
#include<bits/stdc++.h>
using namespace std;

vector<string> getcomps(string temp) {
    vector<string> comps;
    comps.push_back(string("/"));
    for(int i = 1; i < temp.length(); i++) {
        if(temp[i] == '/') {
            comps.push_back(temp.substr(0, i));
        }
    }
    comps.push_back(temp);
    return comps;
}
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        set<string> present;
        printf("Case #%d: ", qq);
        int n, m;
        cin >> n >> m;
        string newDir;
        present.insert("/");
        for(int i = 0; i < n; i++) {
            cin >> newDir;
            present.insert(newDir);
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            cin >> newDir;
            vector<string> comps = getcomps(newDir);
            for(int j = 0; j < comps.size(); j++) {
                if(present.find(comps[j]) == present.end()) {
                    
                    present.insert(comps[j]);
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
