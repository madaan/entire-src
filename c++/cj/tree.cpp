//sg
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll strInt(string path) {
    ll n = path.length();
    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(path[i] == '1') {
            ll add = (1ll << (n - i - 1));
            res += add;
        }
    }
    return res;
}


    
ll findPos(ll p, ll q) {
    string path = "";
    while(!(p == 1 && q == 1)) {
        if(p > q) {
            p = p - q;
            path = "1" + path;
        } else {
            q = q - p;
            path = "0" + path;
        }
    }
    path = "1" + path;
    return strInt(path);
}

void llStr2(ll n, string &bin) {
    while(n > 0) {
        if(n & 1) {
            bin = "1" + bin;
        } else {
            bin = "0" + bin;
        }
        n = n / 2;
        //cout << bin << "\n" << n << "\n";
    }
}




void findElem(ll n) {
    string bin;
    llStr2(n, bin);
    ll p = 1, q = 1;
    //cout << bin << "\n";

    for(int i = 1; i < bin.length(); i++) {
        if(bin[i] == '0') { //left
            q = p + q;
        } else {
            p = p + q;
        }
    }
    cout << p << " " << q << "\n";
}

int main() {
    int t, id;
    cin >> t;
    ll n, p, q;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        cin >> id;
        if(id == 1) {
            cin >> n;
            findElem(n);
        } else {
            cin >> p >> q;
            cout << findPos(p, q) << "\n";
        }
    }
    return 0;
}
