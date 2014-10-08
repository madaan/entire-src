//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int n, tmp;
        cin >> n;
        vector<bool> isOdd(n + 1, false);
        vector<int> alex, bob;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            if(tmp % 2 == 0) {
                bob.push_back(tmp);
            } else {
                alex.push_back(tmp);
                isOdd[i] = true;
            }
        }
        sort(alex.begin(), alex.end());
        sort(bob.begin(), bob.end(), greater<int>());
        int bobI = 0, alexI = 0;
        for(int i = 0; i < n; i++) {
            if(isOdd[i]) {
                cout << alex[alexI++] << " ";
            } else {
                cout << bob[bobI++] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
