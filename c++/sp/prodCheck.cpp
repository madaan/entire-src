//sg
#include<bits/stdc++.h>
using namespace std;
int getprod(string x) {
    int res = 1;
    for(int i = 0, l = x.length(); i < l; i++) {
        res = res * int(x[i] - 48);
    }
    return res;
}

int main() {
    string ip;
    cin >> ip;
    int l = ip.length();
    set<int> prodSet;
    for(int i = 0; i < l; i++) {
        for(int ws = 1; ws <= l - i; ws++) {
            string sub = ip.substr(i, ws); //get the substr
            int prod = getprod(sub); //get prod of digits
            if(prodSet.find(prod) != prodSet.end()) { //already there?
                cout << "false\n";
                return 0;
            } else {
                prodSet.insert(prod);
            }
        }
    }
    cout << "true\n";
    return 0;
}
