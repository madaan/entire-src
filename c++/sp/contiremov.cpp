//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    size_t spos;
    int str2l = str2.length();
    while((spos = str1.find(str2)) != string::npos) {
        str1.erase(spos, str2l);
    }
    cout << str1 << "\n";
    return 0;
}
