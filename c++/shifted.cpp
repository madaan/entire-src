//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    string line1 = "qwertyuiop";
    string line2 = "asdfghjkl;";
    string line3 = "zxcvbnm,./";
    map<char, char> left, right;
    for(int i = 1; i < line1.length(); i++) {
        left[line1[i]] = line1[i - 1];
        left[line2[i]] = line2[i - 1];
        left[line3[i]] = line3[i - 1];
    }

    for(int i = 0; i < line1.length() - 1; i++) {
        right[line1[i]] = line1[i + 1];
        right[line2[i]] = line2[i + 1];
        right[line3[i]] = line3[i + 1];
    }
    char dir;
    string ip;
    cin >> dir;
    cin >> ip;
    if(dir == 'R') {
        for(int i = 0; i < ip.length(); i++) {
            cout << left[ip[i]];
        }
    } else {
        for(int i = 0; i < ip.length(); i++) {
            cout << right[ip[i]];
        }
    }
    cout << "\n";
    return 0;
}








