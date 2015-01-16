//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef vector<int> vi;
    typedef vi::iterator vit;
    //returns the index of the kth element in the combined arrays a and b
    int kth(vi A, int m, vi B, int n, int k) {
        int al = 0, ar = m - 1;
        int bl = 0, br = n - 1;
        //first search in A
        while(al <= ar) {
            int mid = al + (ar - al) / 2;
            vit bpos = upper_bound(B.begin(), B.end(), A[mid]) - 1;
            int net_dist = mid + distance(B.begin(), bpos);
            if(net_dist == k) {
                return A[mid];
            } else if(net_dist > k) { //need to go left
                ar = mid - 1;
            } else {
                al = mid + 1;
            }
        }
        //next search B
        while(bl <= br) {
            int mid = bl + (br - bl) / 2;
            vit bpos = upper_bound(A.begin(), A.end(), B[mid]) - 1;
            int net_dist = mid + distance(A.begin(), bpos);
            if(net_dist == k) {
                return B[mid];
            } else if(net_dist > k) { //need to go left
                br = mid - 1;
            } else {
                bl = mid + 1;
            }
        }
        return -1;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = (m + n) / 2;
        if(m == 0) {
            if(n % 2) {
                return B[k];
            } else {
                return (static_cast<double>(B[k] + B[k - 1]) / 2);
            }
        }
        if(n == 0) {
            if(m % 2) {
                return A[k];
            } else {
                return (static_cast<double>(A[k] + A[k - 1]) / 2);
            }
        }
        if((m + n) % 2 == 0) {
            double res = kth(vector<int>(A, A + m), m, vi(B, B + n), n, k);
            cout << res << "\n";
            res += kth(vector<int>(A, A + m), m, vi(B, B + n), n, k - 1);
            res = res / 2;
            return res;
        }
        return kth(vector<int>(A, A + m), m, vi(B, B + n), n, k);
    }
};


int main() {
    //int a[] = {1, 3, 4, 5, 7};
    int a[] = {1};
    //int b[] = {2,  8, 10, 12, 15};
    int b[] = {1};
    Solution s;
    cout << s.findMedianSortedArrays(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0])) << "\n";
    return 0;
}
