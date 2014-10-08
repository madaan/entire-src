//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    double g = 9.8;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        double v, d;
        cin >> v >> d;
        double angle = (d * g) / (v * v);
        printf("%0.6f\n", (asin(angle) / 2) * (180.0 / M_PI));
    }
    return 0;
}

