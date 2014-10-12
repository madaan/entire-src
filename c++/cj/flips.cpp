//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< string > vs;
typedef unsigned int ui;
//what should be flipped in a to get to b
int n, l;
string getflipstr(string &a, string &b) {
    string res(l, ' ');
    for(ui i = 0; i < l; i++) {
        if(a[i] == b[i]) {
            res[i] = '0';
        } else {
            res[i] = '1';
        }
    }
    return res;
}
set< string > getflips(vs &elec, vs &dev) {
    set< string > flips;
    for(ui i = 0; i < elec.size(); i++) {
        for(ui j = 0; j < dev.size(); j++) {
            flips.insert(getflipstr(elec[i], dev[j]));
        }
    }
    return flips;
}

vs flip(vs &strs, string fstr) {
    vs res(n, string(l, ' '));
    for(ui i = 0 ; i < strs.size(); i++) {
        for(ui j = 0; j < l; j++) {
            if(fstr[j] == '1') {
                res[i][j] = strs[i][j] == '0' ? '1' : '0';
            } else {
                res[i][j] = strs[i][j];
            }
        }
    }
        return res;
}

bool isFlipValid(string flipString, vs &elec, vs &dev) {
    vs flipped = flip(elec, flipString);
    map< string, int > count;
    for(ui i = 0, fs = flipped.size(); i < fs; i++) {
        if(count.find(flipped[i]) == count.end()) {
            count.insert(pair<string, int> (flipped[i], 1));
        } else {
            count[flipped[i]] = count[flipped[i]] + 1;
        }
    }
    bool res = true;
    for(ui i = 0, sz = dev.size(); i < sz; i++) {
        map< string, int >::iterator pos = count.find(dev[i]);
        if(pos == count.end() || count[dev[i]] == 0) {
            res = false;
            break;
        }
        count[dev[i]] = count[dev[i]] - 1;
    }
    //flip(elec, flipString);
    return res;
}

void updateMin(int &ans, string f) {
    int l = 0;
    for(ui i = 0, len = f.length(); i < len; i++) {
        if(f[i] == '1') {
            l++;
        }
    }
    ans = min(ans, l);
}
int ones(string s) {
    int res = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '1') res++;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        cin >> n >> l;
        vs elec, dev;
        string temp;
        for(ui i = 0; i < n; i++) {
            cin >> temp;
            elec.push_back(temp);
        }
        for(ui i = 0; i < n; i++) {
            cin >> temp;
            dev.push_back(temp);
        }
        set< string > flips = getflips(elec, dev);
        int ans = 10000000;
        typedef pair<int, string> vis;
        vector< vis > prep;
        for(set< string >::iterator flip = flips.begin(); flip != flips.end(); flip++) {
            prep.push_back(vis(ones(*flip), *flip));
        }
        sort(prep.begin(), prep.end());

        for(int i = 0, ps = prep.size(); i < ps; i++) {
            //cout << *flip << "\n";
            bool res = isFlipValid(prep[i].second, elec, dev);
            if(res) {
                ans = prep[i].first;
                break;
            }
        }
        if(ans == 10000000) {
            cout << "NOT POSSIBLE\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
