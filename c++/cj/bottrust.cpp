//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        int n;
        cin >> n;
        int ctime = 0, last_o = 1, last_b = 1, last_ot = 0, last_bt = 0;
        for(int i = 0; i < n; i++) {
            char c;
            int sw;
            cin >> c >> sw;
            if(c == 'B') {
                int timeSinceLast = abs(last_bt - ctime);
                int timeNeeded = abs(last_b - sw);
                if(timeSinceLast >= timeNeeded) {
                    ctime++;
                } else {
                    timeNeeded = timeNeeded - timeSinceLast;
                    ctime += timeNeeded + 1;
                }
                last_b = sw;
                last_bt = ctime;
            } else {
                int timeSinceLast = abs(last_ot - ctime);
                int timeNeeded = abs(last_o - sw);
                if(timeSinceLast >= timeNeeded) {
                    ctime++;
                } else {
                    timeNeeded = timeNeeded - timeSinceLast;
                    ctime += timeNeeded + 1;
                }
                last_o = sw;
                last_ot = ctime;
            }
        }
        cout << ctime << "\n";
    }
    return 0;
}
