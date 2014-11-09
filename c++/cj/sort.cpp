//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<string> adj[10000];
        map<string, int> vname;
        map<int, string> vnom;
        int vno = 0;
        for(int i = 0; i < n; i++) {
            cin >> str1;
            cin >> str2;
            if(vname.find(str1) == vname.end()) {
                vname[str1] = vno;
                vnom[vno] = str;
                vno++;
            }
            if(vname.find(str2) == vname.end()) {
                vname[str2] = vno;
                vnom[vno] = str;
                vno++;
            }
            adj[vname[str1]].push_back(str2);








