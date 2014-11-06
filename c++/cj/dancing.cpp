//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        int n, s, p;
        cin >> n >> s >> p;
        int res = 0;
        for(int i = 0; i < n; i++) {
            int total;
            cin >> total;
            
            if(total >= (p * 3)) {
                res++;
                continue;
            }
            total = total - p;
            if((p - 1) >= 0 && total >= ((p - 1) * 2)) {
                res++;
            } else if((p - 2 >= 0) && s > 0 && (total >= ((p - 2) * 2))) {
                s--;
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}

