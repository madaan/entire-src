//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        int a, b;
        cin >> a >> b;
        double *cprob = new double[a];
        double *wprob = new double[a];
        for(int i = 0; i < a; i++) {
            cin >> cprob[i];
            wprob[i] = 1 - cprob[i];
        }
        double *noFaultTill = new double[a];
        double *atLeastOneFrom = new double[a];
        noFaultTill[0] = cprob[0];
        for(int i = 1; i < a; i++) {
            noFaultTill[i] = cprob[i] * noFaultTill[i - 1];
        }
        for(int i = a - 1; i >= 0; i--) {
            atLeastOneFrom[i] = 1 - (noFaultTill[a] / noFaultTill[i - 1]);
        }
        double enter = b + 2;
        double pmiss = 1 - noFaultTill[a - 1];
        double pnmiss = 1 - pmiss;
        double keepOn = pmiss * (2 * b - a + 2) + pnmiss * (b - a + 1);
        //now calculate the expected value on pressing from one to a backspaces
        double bsmin = 10000000009;
        for(int bs = 1; bs <= a; bs++) {
            double probMistake = noFaultTill[a - bs - 1] * atLeastOneFrom[a - bs];
            double expVal = probMistake * (b - a + 2 * bs + 1) + (1 - probMistake) * (b - a + 2 * bs + 1 + b + 1);
            bsmin = min(expVal, bsmin);
        }
        cout << fixed <<  setprecision(6) << min(bsmin, min(enter, keepOn)) << "\n";
    }
    return 0;
}
