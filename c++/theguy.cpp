//sg
#include<bits/stdc++.h>
using namespace std;
int levels[200];
int main() {
    int n, p, q, temp;
    cin >> n;
    cin >> p;
    for(int i = 0; i < p; i++) {
        cin >> temp;
        levels[temp] = 1;
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> temp;
        levels[temp] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(levels[i] == 0) {
            cout << "Oh, my keyboard!\n";
            return 0;
        }
    }
    cout << "I become the guy.\n";
    return 0;
}




