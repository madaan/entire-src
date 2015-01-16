//sg
#include<bits/stdc++.h>
using namespace std;
int maxProduct(int a[], int n) {
    int *lpp = new int[n];
    int *lnp = new int[n];
    lpp[0] = lnp[0] = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] >= 0) {
            lpp[i] = (lpp[i - 1] <= 0 ? a[i] : lpp[i - 1] * a[i]);
            lnp[i] = (lnp[i - 1] < 0 ? lnp[i - 1] * a[i] : a[i]);
        } else {
            lpp[i] = (lnp[i - 1] < 0 ? lnp[i - 1] * a[i] : a[i]);
            lnp[i] = (lpp[i - 1] > 0 ? lpp[i - 1] * a[i] : a[i]);
        }
    }
    int maxe = lpp[0];
    for(int i = 1; i < n; i++) {
        maxe = max(maxe, lpp[i]);
    }
    return maxe;
}
int main() {
    int arr[] = {-1, -2, -9, -6};
    cout << maxProduct(arr, 4) << "\n";
    return 0;
}
