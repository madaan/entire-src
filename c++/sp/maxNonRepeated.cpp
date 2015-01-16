//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<int, int> pmap;
    int arr[] = {1, 2, 3, 3, 4, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    int sum = 0;
    int gmax = 0;
    int left_ptr = 0;
    for(int i = 0; i < n; i++) {
        if(pmap[vec[i]] != 0) {//found a repeated elment
            while(vec[left_ptr] != vec[i]) {
                sum = sum - vec[left_ptr];
                pmap[vec[left_ptr]] = 0;
                left_ptr++;
            }
            left_ptr++; //skip it
        } else {
            pmap[vec[i]] = 1;
            sum += vec[i];
            gmax = max(sum, gmax);
        }
    }
    cout << gmax << "\n";
    return 0;
}

