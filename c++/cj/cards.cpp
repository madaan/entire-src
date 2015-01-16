//sg
#include<bits/stdc++.h>
using namespace std;
int delRep(vector< int > arr) {
    bool foundRep = false;
    int l = arr.size();
    while(true) {
        l = arr.size();
        for(int i = 0; i <  l - 2; i++) {
            if(arr[i] != 0 && arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
                arr[i] = arr[i + 1] = arr[i + 2] = 0;
                foundRep = true;
                break;
            }
        }
        if(!foundRep) {
            break;
        }
        arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
        foundRep = false;
    }
    int res = 0;
    for(int i = 0; i < l; i++) {
        if(arr[i] != 0) {
            res++;
        }
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int n, k;
        cin >> n >> k;
        vector< int > arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << delRep(arr) << "\n";
    }
    return 0;
}
