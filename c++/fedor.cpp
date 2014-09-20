//sg
#include<bits/stdc++.h>
using namespace std;

int numdiff(string a, string b) {
    int res = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i]) {
            res++;
        }
    }
    return res;
}


int main() {
    int n, m, k, x;
    int res = 0;
    cin >> n >> m >> k;
    vector<string> bitstrs;
    for(int i = 0; i < m + 1; i++) {
        cin >> x;
        bitstrs.push_back(std::bitset< 64 >( x ).to_string()); // string conversion);
    }
    for(int i = 0; i < m; i++) {
        if(numdiff(bitstrs[i], bitstrs[m]) <= k) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
