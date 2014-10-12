//sg
#include<bits/stdc++.h>
using namespace std;
vector< string > currConfig(vector< int > pos) {
    const char* orig[] = {
        "1111011", //9
        "1111111", //8
        "1110000",
        "1011111",
        "1011011", //5
        "0110011",
        "1111001",
        "1101101",
        "0110000", //1
        "1111110"
    };
        "1011011", //9
        "1011011", //8
        "1010000",
        "1011011",
        "1011011", //5
        "0010011",
        "1011001",
        "1001001",
        "0010000", //1
        "1011010"
 
    vector< string > ori(orig, orig + 10);
    vector< string > res;
    for(int i = 0; i < 10; i++) {
        string temp = orig[i];
        for(int j = 0; j < pos.size(); j++) {
            temp[pos[j]] = '0';
        }
        res.push_back(temp);
    }
    return res;
}

void andstr(string &a, string b) {
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '0' && b[i] == '0') {
            a[i] = '0';
        } else {
            a[i] = '1';
        }
    }
}

vector< int > pos(vector< string > &states) {
    string res(states[0]);
    for(int i = 1; i < states.size(); i++) {
        //cout << " here: " << res << " " << i << "\n";
        andstr(res, states[i]);
    }
    vector< int > offpos;
    for(int i = 0; i < res.length(); i++) {
        if(res[i] == '0') {
            offpos.push_back(i);
        }
    }
    return offpos;
}

//determines if state sequence is appears as a subsequence of the current
//cycles that are possible

bool issub(vector< string > state, vector< string > config, int start, int &ans) {
    int c_ptr = start;
    int i = 0;
    //cout << "start : " << start << "\n";
    while(i < state.size() && state[i] == config[c_ptr]) {
    #ifdef debug
        cout << state[i] << " == " << config[c_ptr] << "\n";
    #endif
        i++;
        c_ptr = (c_ptr + 1) % 10;
    }
    #ifdef debug
    cout << "i = " << i << "\n";
    #endif
    if(i == state.size()) {
        ans = (c_ptr) % 10;
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int n;
        cin >> n;
        vector < string > states(n, "");
        for(int i = 0; i < n; i++) {
            cin >> states[i];
        }
        vector< int > offpos = pos(states);
        for(int i = 0; i < offpos.size(); i++) {
            //cout << offpos[i] << "\n";
        }
        vector< string > currstates = currConfig(offpos);
        vector<int> possibleBegins;
        //verify that the ans is not ambiguous
        for(int i = 0; i < currstates.size(); i++) {
            cout << currstates[i] << "\n";
            if(states[0] == currstates[i]) {
                possibleBegins.push_back(i);
            }
        }
        int matches = 0;
        int ans;
        for(int i = 0; i < possibleBegins.size(); i++) {
            if(issub(states, currstates, possibleBegins[i], ans)) {
                matches++;
            }
        }
        //cout << "matches : " << matches << "\n";
        //cout << "ans : " << ans << "\n";
        if(matches != 1) {
            cout << "ERROR!\n";
        } else {
            cout << currstates[ans] << "\n";
        }
    }
    return 0;
}
