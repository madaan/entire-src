//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    //first row
    cout << "+------------------------+\n";
    int r1 = (k + 1) / 3;
    int r2 = (k) / 3;
    int r3 = (k - 1) / 3;
    if(k > 0 && k < 4) {
        r1 = 1;
    }
    if(k > 1 && k < 4 ) {
        r2 = 1;
    }
    if(k > 3 && k <= 4 ) {
        r3 = 1;
    }
    if(k > 1 && k < 4 ) {
        r2 = 1;
    }
    cout << "|";
    for(int i = 0; i < r1; i++) {
        cout << "O.";
    }
    for(int i = 0; i < (11 - r1); i++) {
        cout << "#.";
    }
    cout <<"|D|)\n";
    cout << "|";
    for(int i = 0; i < r2; i++) {
        cout << "O.";
    }
    for(int i = 0; i < (11 - r2); i++) {
        cout << "#.";
    }
    cout <<"|.|\n";
    cout << "|";
    if(k > 2) {
        cout << "O.";
    } else {
        cout << "#.";
    }
    cout << "......................|\n";
    cout << "|";
    for(int i = 0; i < r3; i++) {
        cout << "O.";
    }
    for(int i = 0; i < (11 - r3); i++) {
        cout << "#.";
    }
    cout <<"|.|)\n";
    cout << "+------------------------+\n";
    return 0;
}
