//sg
#include<stdio.h>
typedef long long ll;
#define min(a, b) ((a < b) ? a : b)
int main() {
    int t;
    scanf("%d", &t);
    ll x, y;
    while(t--) {
        ll res = 0;
        scanf("%lld%lld", &x, &y);
        if(x < 0) {
            x = -x;
        }
        if(y < 0) {
            y = -y;
        }
        ll minxy = min(x, y);
        x -= minxy;
        y -= minxy;
        res += (2 * minxy);
        if(x == 0) { //need to go up
            res += ((y % 2 == 0) ? (2 * y) : (2 * y - 1));
        } else if(y == 0) {
            res += ((x % 2 == 0) ? (2 * x) : (2 * x + 1));
        }
        printf("%lld\n", res);
    }
    return 0;
}
