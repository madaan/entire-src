//sg
#include<bits/stdc++.h>
using namespace std;
double dp[401][80001];
int level[80001]; //returns the level of a number
void fillLevel() {
    int total = 1;
    for(int lvl = 1; total < 80001; lvl++) {
        for(int j = 1; j <= lvl; j++) {
            level[total] = lvl;
            total++;
        }
    }
}
int solve(double x) {
    int lvl = 1;
    dp[1][1] = x;
    bool atleastOne = false;
    while(true) { //while there is wine left
        for(int gn = 1; gn <= (lvl * (lvl + 1)) / 2; gn++) {
            if(dp[lvl][gn] > 250) {
                atleastOne = true;
                double present = dp[lvl][gn];
                dp[lvl][gn] = 250;
                present = present - 250;
                present = present / 3;
                dp[lvl + 1][gn] += present;
                dp[lvl + 1][gn + level[gn] + 1] += present;
                dp[lvl + 1][gn + level[gn]] += present;
            }
        }
        if(!atleastOne) {
            break;
        }
        lvl++;
        atleastOne = false;
    }
}
int main() {
    fillLevel();
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        memset(dp, 0, sizeof(dp));
        printf("Case #%d: ", tt);
        int b, l, n;
        cin >> b >> l >> n;
        double wine = b * 750;
        solve(wine);
        cout << fixed << setprecision(7) << fixed << dp[l][n] << "\n";
    }
    return 0;
}
