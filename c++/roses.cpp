//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 31) {
            cout << "CHETU 1\n";
            continue;
        }
        if((32 - n) % 2 == 0) {
            cout << "CHETU " << (32 - n) << "\n";
        } else {
            cout << "NISHU " << (32 - n) << "\n";
        }
    }
    return 0;
}

