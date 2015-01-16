//sg
#include<bits/stdc++.h>
using namespace std;
int findHighBit(int n) {
    int hb = -1; //no bit is set
    int r = 1;
    for(int i = 0; i < 32; i++) {
        if(n & r) {
            hb = i;
        }
        r = r << 1;
    }
    return hb;
}

int main() {
    int n = 165;
    int hb = findHighBit(n);
    cout << "Highest bit : " << hb << "\n";
    if(hb == -1) {
        cout << "0\n";
        return 0;
    }
    int rhn = 0;
    int pw = 1 << ((hb - 1) / 2);
    int pwr = 1;
    cout << pw << "\n";
    int ncopy = n;
    for(int i = 0; i <= (hb / 2); i++) {
        if(n & pwr) {
            rhn = rhn | pw;
        }
        pw = pw >> 1;
        pwr = pwr << 1;
        ncopy = ncopy >> 1;
    }
    cout << ncopy << "\n";
    cout << rhn << "\n";
    if(rhn == ncopy) {
        cout << "Pali\n";
    } else {
        cout << "Not Pali\n";
    }
    return 0;
}

