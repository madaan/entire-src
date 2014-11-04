//sg
#include<bits/stdc++.h>
using namespace std;
int graph[26][26];
int degree[26];
bool present[26];
#define INF 10000
vector< pair<int, char> > res;
void addEdge(char a, char b) {
    graph[a - 97][b - 97] = 1;
    degree[b - 97]++;
    present[a - 97] = present[b - 97] = true;
}
class DFSHandler {
    vector< bool > visited;
    stack< int > tsort;
    int time;
    public:
    DFSHandler() {
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(present[i]) {
                cnt++;
            }
        }
        visited = vector< bool > (cnt, false);
    }

    void dfs(int src, int t) {
        visited[src] = true;
        for(int i = 0; i < 26; i++) {
            if(i != src && graph[src][i] != INF && !visited[i]) {
                dfs(i, t + 1);
            }
        }
        tsort.push(src);
        res.push_back(pair<int, char> (t, char(src + 97)));
    }

    void dfsdrive() {
        vector<pair<int, int> > chardeg;
        for(int i = 0; i < 26; i++) if(present[i]) {
            chardeg.push_back(pair<int, int>(degree[i], i));
        }
        sort(chardeg.begin(), chardeg.end());
        for(int i = 0, l = chardeg.size(); i < l; i++) {
            if(present[i] && !visited[chardeg[i].second]) {
                dfs(chardeg[i].second, 0);
            }
        }
        /*
        sort(res.begin(), res.end());
        cout << res[0].second;
        int ptime = res[0].first;
        for(int i = 1, l = res.size(); i < l; i++) {
            if(res[i].first != ptime) {
                ptime = res[i].first;
                cout << "\n";
            }
            cout << res[i].second;
        }
        cout << "\n";
        */
        int dist[26];
        for(int i = 0; i < 26; i++) {
            dist[i] = 0;
        }
        while(!tsort.empty()) {
            int curr = tsort.top();
            tsort.pop();
            for(int i = 0; i < 26; i++) {
                if(graph[curr][i] != INF) {
                    if(dist[i] < dist[curr] + 1) {
                        dist[i] = dist[curr] + 1;
                    }
                }
            }
        }
        vector< pair<int, char> > distChar;
        for(int i = 0; i < 26; i++) {
            if(present[i]) {
                distChar.push_back(pair<int, char> (dist[i], char(i + 97)));
            }
        }
        sort(distChar.begin(), distChar.end());

        cout << distChar[0].second;
        int ptime = distChar[0].first;
        for(int i = 1, l = distChar.size(); i < l; i++) {
            if(distChar[i].first != ptime) {
                ptime = distChar[i].first;
                cout << "\n";
            }
            cout << distChar[i].second;
        }
        cout << "\n";
    }
};

int main() {
    int w;
    cin >> w;
    vector< string > words(w);
    vector<string> order;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            graph[i][j] = INF;
        }
    }
    for(int i = 0; i < w; i++) {
        cin >> words[i];
        words[i] = "." +words[i];
    }
    for(int i = 1; i < w; i++) {
        int cl = words[i].length();
        int pl = words[i - 1].length();
        int cp = 0, pp = 0;
        while(words[i][cp] && words[i - 1][pp] && (words[i][cp] == words[i - 1][pp])) {
            cp++;
            pp++;
        }
        if(cp == cl || pp == pl) continue;
        addEdge(words[i - 1][pp], words[i][cp]);
    }
    /*
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(graph[i][j] != INF) {
                cout << i << "- > " << j << "\n";
            }
        }
    }
    */


        DFSHandler dfh;
        dfh.dfsdrive();
    return 0;
}
