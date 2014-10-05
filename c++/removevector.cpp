//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {5, 2, 9, 14, 1, 12, 4};
    int indx_arr[] = {3, 6, 1};
    vector<int> A(arr, arr + sizeof(arr) / sizeof(arr[0]));
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    vector<int> B(indx_arr, indx_arr + sizeof(indx_arr) / sizeof(indx_arr[0]));
    sort(B.begin(), B.end(), greater<int>());
    cout << "\n";
    for(int i = 0; i < B.size(); i++) {
        A.erase(A.begin() + B[i]);
    }
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }

    
    cout << "\n";
    return 0;
}

