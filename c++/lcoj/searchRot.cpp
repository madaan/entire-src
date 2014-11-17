//sg
#include<bits/stdc++.h>
using namespace std;

 int searchInsert(int A[], int n, int target) {
    //finds the first index which is > target
    if(A[0] > target) {
        return 0;
    }
    if(n == 1) {
        return A[0] >= target ? 0 : 1;
    }
    if(n == 2) {
        if(A[0] >= target) {
            return 0;
        } else if(A[1] >= target) {
            return 1;
        } else {
            return 2;
        }
    }
    int l = 0, r = n - 1;
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(A[mid] >= target) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //at this point, r is the first vertex where A[r] >= target
    int res = A[l] >= target ? l : r;
    if(A[res] < target) {
        return res + 1;
    } else {
        return res;
    }
}

//finds the first flipped index
int checkFlip(int A[], int n) {
    int l = 0, r = 1;
    int pvt = A[0];
    while(r < n && A[r] >= pvt) {
        l = r;
        r = r * 2;
    }
    if(r > n) {
        r = n - 1;
    }
    //invariant, r always has A[r] < pvt
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(A[mid] < pvt) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int search(int A[], int n, int target) {
    if(n == 0) {
        return -1;
    }
    if(n == 1) {
        return A[0] == target ? 0 : -1;
    }
    int flpd = checkFlip(A, n);
    vector<int> arr(A, A + n);
    vector<int>::iterator i = lower_bound(arr.begin(), arr.begin() + flpd, target);
    if(*i == target) {
        return i - arr.begin();
    }
    i = lower_bound(arr.begin() + flpd, arr.end(), target);
    if(*i == target) {
        return i - arr.begin();
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5};
    //int arr[] = {4, 5, 6, 7, 0, 1, 2};
    cout << searchInsert(arr, 3, 6) << "\n";
    return 0;
}
