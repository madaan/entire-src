//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lldivide(long long dividend, long long divisor) {
        int res = 0;
        bool nn = dividend < 0;
        bool dn = divisor < 0;
        if(dividend < 0) dividend = -dividend;
        if(divisor < 0) divisor = -divisor;
        if(divisor > dividend) {
            return 0;
        }
        
        
        int l = 1;
        int r = 2;
        while((dividend / r) >= divisor) {
            l = r;
            r = r * 2;
            
        }
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if((dividend / mid) >= divisor) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return (nn ^ dn) ? -l : l;
    }

    int divide(int dividend, int divisor) {
        return lldivide(dividend, divisor);
    }
};

int main() {
    Solution s;
    cout << s.divide(-1010369383, -2147483648) << "\n";
    return 0;
}
