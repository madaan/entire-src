#include<bits/stdc++.h>
using namespace std;

int bitFlip2(vector <int> arr) {
    int n = arr.size();
    vector<int> za(n + 2, 0);
    vector<int> zp(n + 2, 0);
    vector<int> oa(n + 2, 0);
    vector<int> op(n + 2, 0);

    for(int i = n - 1; i >= 0; i--) {
        za[i] = arr[i] == 0 ? za[i + 1] + 1 : za[i + 1];
        oa[i] = arr[i] == 1 ? oa[i + 1] + 1 : oa[i + 1];
    }
    zp[0] = arr[0] == 0 ? 1 : 0;
    op[0] = 1 - zp[0];
    for(int i = 1; i < n ; i++) {
        zp[i] = arr[i] == 0 ? zp[i - 1] + 1 : zp[i - 1];
        op[i] = arr[i] == 1 ? op[i - 1] + 1 : op[i - 1];
    }


    int ans = 0;
    bool winStart = false;
    int p;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            if(winStart) {
                winStart = false;
                ans = max(ans, i - p);
            }
        } else if(!winStart) {
            winStart = true;
            p = i;

        }
    }
    return ans;
}

int bitFlip3(vector<int> arr) {
    int sum = 0;
    int gmax = 0;
    int max_ending_here = 0, max_so_far = 0;
    int st, en;
    int md = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int d;
        if(arr[i] == 1) {
            d = 0;
        }
        else {
            d = 1;
        }
        max_ending_here = max(max_ending_here + d, 0);
        if(max_so_far < max_ending_here) {
            md = max(md, i - st + 1);
            st = i + 1;
            max_so_far   = max(max_ending_here, max_so_far);
        }
    }
    return md;
}
int bitFlip(vector < int > arr) {
    return bitFlip3(arr);
    int n = arr.size();
    vector<int> za(n + 2, 0);
    vector<int> zp(n + 2, 0);
    vector<int> oa(n + 2, 0);
    vector<int> op(n + 2, 0);

    for(int i = n - 1; i >= 0; i--) {
        za[i] = arr[i] == 0 ? za[i + 1] + 1 : za[i + 1];
        oa[i] = arr[i] == 1 ? oa[i + 1] + 1 : oa[i + 1];
    }
    zp[0] = arr[0] == 0 ? 1 : 0;
    op[0] = 1 - zp[0];
    for(int i = 1; i < n ; i++) {
        zp[i] = arr[i] == 0 ? zp[i - 1] + 1 : zp[i - 1];
        op[i] = arr[i] == 1 ? op[i - 1] + 1 : op[i - 1];
    }

    int ans = 0;
    //scan with zp and oa
    for(int i = 1; i < n; i++) {
        //cout << op[i] << " ";
        ans = max(ans, op[i - zp[i - 1]] + zp[i - 1] + oa[i]);
        ans = max(ans, op[i - 1] + za[i]);
    }
    return ans;
}



int main() {
    int arr[] = {1, 0, 0, 0, 1};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << bitFlip(vec) << "\n";
    return 0;
}
