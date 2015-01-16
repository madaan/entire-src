//sg
#include<bits/stdc++.h>
using namespace std;
int getSum(int n) {
    if(n % 2) {
        return (n / 2) * (n + 1);
    } else {
        return ((n + 1) / 2) * n;
    }
}
int firstMissingPositive(int A[], int n) {
    int nm, nx, pm, px;
    bool neg = false, pos = false;
    int posSum = 0;
    int negSum = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] < 0) {
            neg = true;
            nm = nx = -A[i];
        } else if(A[i] > 0) {
            pos = true;
            pm = px = A[i];
        }
        if(neg && pos) break;
    }
    for(int i = 0; i < n; i++) {
        if(A[i] < 0) {
            int tmp = -A[i];
            if(tmp > nx) {
                nx = tmp;
            } else if(tmp < nm) {
                nm = tmp;
            }
            negSum += tmp;
        } else if(A[i] > 0) {
            if(A[i] > px) {
                px = A[i];
            } else if(A[i] < pm) {
                pm = A[i];
            }
            posSum += A[i];
        }
    }
    int iposSum = getSum(px) - getSum(pm - 1);
    int inegSum = getSum(nx) - getSum(nm - 1);
    cout << posSum << "\n";
    cout << negSum << "\n";
    cout << iposSum << "\n";
    cout << inegSum << "\n";
    if(iposSum > posSum) {
        return iposSum - posSum;
    } else {
        return -(inegSum - negSum);
    }
}
int main() {
    int a[] = {3, 4, -1, 1};
    cout << firstMissingPositive(a, 4) << "\n";
    return 0;
}
