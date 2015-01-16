//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 6;
    int arr[] = {12, 13, 2, 18, 1, 6};
    vector<int> v(arr, arr + n);
    vector<int> sumTo(n, 0), sumFrom(n, 0);
    sumFrom[n -  1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        sumFrom[i] = sumFrom[i + 1] + v[i + 1];
    }
    sumTo[0] = 0;
    for(int i = 1; i <= n - 1; i++) {
        sumTo[i] = sumTo[i - 1] + v[i - 1];
    }
    for(int i = 0; i < n; i++) {
        if(sumTo[i] == sumFrom[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
