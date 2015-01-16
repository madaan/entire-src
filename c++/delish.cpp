//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< ll > vi;
void kadane(int i, int j, ll &gmax, int &starts, vi ar) {
    ll cmax = 0ll;
    gmax = 0ll;
    int currStart = i;
    starts = i;
    for(; i <= j; i++) {
        cmax = max(0ll, cmax + ar[i]);
        if(cmax == 0ll) {
            currStart = i + 1;
        }
        if(cmax > gmax) {
            gmax = cmax;
            starts = currStart;
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vi a(n);
        vi ainv(n);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            ainv[i] = -a[i];
        }
        //try min - max
        ll rmax, lmax, lmin, rmin;
        int rmax_s, rmin_s;
        int temp;
        kadane(1, n - 1, rmax, rmax_s, a);
        kadane(0, rmax_s - 1, lmin, temp, ainv);
        ll ans1 = abs(lmin + rmax);
        kadane(1, n - 1, rmin, rmin_s, ainv);
        kadane(0, rmin_s - 1, lmax, temp, a);
        ll ans2 = abs(lmax + rmin);
        printf("%lld\n", max(ans2, ans1));
    }
    return 0;
}
