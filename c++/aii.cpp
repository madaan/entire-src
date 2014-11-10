//sg
#include<bits/stdc++.h>
using namespace std;
int bsearch(int arr[], int n) {
    int l = 0;
    int r = n;
    while(r - l > 1) {
        cout << l << " " << r << "\n";
        int m = l + (r - l) / 2;
        if(arr[m] <= m) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
int main() {
    int arr[] = {-2,-1,0,1,2,3,6,10000,10000};
    int possibleAns = bsearch(arr, 7);
    cout << possibleAns << "\n";
    if(arr[possibleAns] == possibleAns) {
        cout << possibleAns << "\n";
    } else {
        cout << "Such an i doesn't exist\n";
    }
    return 0;
}

