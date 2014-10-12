//sg
#include<bits/stdc++.h>
using namespace std;
vector< int >  delRep(vector< int > arr, bool &del) {
    del = false;
    vector< int > res;
    for(int i = 0, n = arr.size(); i < n; i++) {
        if(i < n - 2 && arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
            del = true;
            i+=2;
        } else {
            res.push_back(arr[i]);
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
        vector< int > res(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            res[i] = arr[i];
        }
        bool valid = true;
        while(valid) {
            //cout << "\n";
            for(int i = 0 ; i < res.size(); i++) {
              //  cout << res[i] << " ";
            }
            res = delRep(res, valid);
        }
        cout << res.size() << "\n";
    }
    return 0;
}

