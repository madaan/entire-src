//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //this cannot be a binary search if the elements are not sorted.
    //in that case, the complexity, has to go up
    //returns the first index which is not >= x
    //or returns -1, in which case the minimum element is the first element
    int srch(vector<int> &num, int x) {
        int l = 0, r = 1;
        int nsize = num.size();
        if(nsize == 1) {
            return 0;
        }
        while(r < nsize && num[r] >= x) {
            l = r;
            r = r * 2;
        }
        if(r >= nsize) {
            r = nsize - 1;
        }
        //invariant : r always has an element < x
        while(r - l > 1) {
            //cout << "l : " << l << "r : " << r << "\n";
            int mid = l + (r - l) / 2;
            if(num[mid] >= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }
    int findMin(vector<int> &num) {
        int i = srch(num, num[0]);
        if(num[i] <= num[0]) {
            return num[i];
        }
        return num[0];
    }
    int trivMin(vector<int> &num) {
        return *(min_element(num.begin(), num.end()));
    }
};
int main() {
    Solution s;
    //int arr[] = {4, 5, 6, 7, 0, 1, 2};
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};//4, 5, 6, 7, 0, 1, 2};
    //int arr[] = {10, 10, 10, 1, 10};
    int arr[] = {3, 1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << s.trivMin(nums) << "\n";
    return 0;
}
