//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int c, n;
        cin >> c >> n;
        vector<int> vals(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> vals[i];
        }
        for(int i = 1; i <= n; i++) {
            int j;
            for(j = 1; j <= n; j++) {
                if(i != j) {
                    if(vals[j] + vals[i] == c) {
                        if(i < j) {
                            cout << i << " " << j << "\n";
                        } else {
                            cout << j << " " << i << "\n";
                        }
                        break;
                    }
                }
            }
            if(j <= n) {
                break;
            }
        }
    }
    return 0;
}
