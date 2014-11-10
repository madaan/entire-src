//sg
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
/*
 * returns a ^ b
 */
ull mpow(ull a, ull b) {
    ull res = 1;
    for(ull i = 0; i < b; i++) {
        res = res * a;
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        string temp;
        cin >> temp;
        map<char, int> valmap;
        set<char> unq;
        for(int i = 0; i < temp.length(); i++) {
            unq.insert(temp[i]);
        }
        unsigned long long base = unq.size();
        //cout << base << "\n";
        if(base == 1) {
            base = 2;
        }
        unsigned long long res = 0;
        valmap[temp[0]] = 1;
        int nxt  = 0;
        for(int i = 0; i < temp.length(); i++) {
            if(valmap.find(temp[i]) == valmap.end()) {
                if(nxt == 1) nxt++;
                valmap[temp[i]] = nxt++;
            }
            unsigned long long coeff = valmap[temp[i]];
            //cout << coeff << " * " << base << " ^ " << temp.length() - i - 1 << " + ";
            //cout << "\n" << res << "\n";
            res += (coeff * mpow(base, temp.length() - i - 1));
        }
        cout << res << "\n";
    }
    return 0;
}
