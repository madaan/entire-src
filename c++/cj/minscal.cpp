//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int n;
        cin >> n;
        vector<long long> v1(n, 0), v2(n, 0);
        for(int i  = 0; i < n; i++) {
            cin >> v1[i];
        }
        for(int i  = 0; i < n; i++) {
            cin >> v2[i];
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<long long>());
        long long res = 0;
        for(int i = 0; i < n; i++) {
            //cout << v1[i] << " " << v2[i] << "\n";
            res += v1[i] * v2[i];
        }
        cout << res << "\n";
    }
    return 0;
}
            
