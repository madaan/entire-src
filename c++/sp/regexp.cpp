//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    int res = 0;
    bool ls;
    ls = false;
    for(int i = 0; str[i]; i++) {
        if(str[i] == '1' && !ls) {
            ls = true;
        } else if(str[i] == '1' && ls) {
            ls = false;
            res++;
            i--;
        } else if(ls && str[i] != '0') { 
            ls = false;
        }
    }
    cout << res << "\n";
    return 0;
}
