//sg
#include<bits/stdc++.h>
using namespace std;
ll fastexp(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b % 2) {
            res = (res * a) % c;
        }
        b = b / 2;
        a = (a * a) % c;
    }
    return res;
}

int main() {
    cout << fastexp(10, 10000, 234) << "\n";
    return 0;
}
