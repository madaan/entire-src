//sg
#include<bits/stdc++.h>
using namespace std;
int l, d, n;
vector< string > dict;
map< pair <char, int> , vector< bool > * > setwordsmap;
void setWords(char c, int pos, vector< bool > &setwords) {
    setwords = *setwordsmap[pair<char, int> (c, pos)];
}
void init() {
    for(int pos = 0; pos < l; pos++) {
        for(char c = 'a'; c <= 'z'; c++) {
            vector< bool > *setwords = new vector<bool>(d, false);
            vector<bool> &sw = *setwords;
            for(int i = 0; i < d; i++) {
                if(dict[i][pos] == c) {
                    sw[i] = true;
                }
            }
            setwordsmap[pair<char, int>(c, pos)] = setwords;
        }
    }
}
vector<bool> getPosWords(string opts, int pos, vector< bool > &flags) {
    for(int i = 0; i < opts.length(); i++) {
        setWords(opts[i], pos, flags);
    }
    return flags;
}
int solve(vector< string > opts) {
    vector< vector< bool > > flags(l, vector<bool>(d,  false));
    for(int i = 0; i < l; i++) {
        getPosWords(opts[i], i, flags[i]);
        cout << "pos : " << i << "\n";
        for(int j = 0; j < d; j++) {
            cout << flags[i][j] << "\n";
        }
    }
    int res = 0;
    vector<bool> fflag(d, true);
    for(int i = 0; i < l; i++) {
        bool isset = true;
        for(int j = 0; j < d; j++) {
            fflag[j] = fflag[j] & flags[i][j];
        }
    }
    for(int j = 0; j < d; j++) {
        if(fflag[j]) {
            res++;
        }
    }
    return res;
}
int main() {
    cin >> l >> d >> n;
    string temp;
    for(int i = 0; i < d; i++) {
        cin >> temp;
        dict.push_back(temp);
    }
    init();
    for(int i = 1; i <= n; i++) {
        vector< string > opts;
        cin >> temp;
        int j = 0;
        int l = temp.length();
        string opt;
        while(j < l) {
            opt = string("");
            if(temp[j] == '(') {
                j++;
                while(temp[j] && temp[j] != ')') {
                    opt += temp[j];
                    j++;
                }
                opts.push_back(opt);
            } else if(temp[j] == ')') {
                j++;
            } else {
                opt += temp[j];
                opts.push_back(opt);
                j++;
            }
        }
        cout << "Case #" << i << ": " << solve(opts) << "\n";
    }
    return 0;
}
