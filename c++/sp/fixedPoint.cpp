//sg
#include<bits/stdc++.h>
using namespace std;

int f_point(int arr[], int n) {
    int l = 0, r = 1;
    while(r < n && arr[r] < r) {
        l = r;
        r = r * 2;
    }
    if(r >= n) {
        r = n - 1;
    }
    //invariant : a[l] < l and a[r] >= r
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(arr[mid] < mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int main() {
    int arr[] = {-2, -1, 0, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << f_point(arr, n) << "\n";
    return 0;
}
