//sg
#include<bits/stdc++.h>
using namespace std;
int MOD = 10;
int abmodn(int a, int b, int n = MOD) {
    if(b == 1) return a % n;
    if(b == 0) return 1;
    int res = abmodn(a, b / 2, n) % n;
    if(b % 2 == 0) {
        return (res * res) % n;
    } else {
        return ((a % n) * (res * res) % n) % n;
    }
}

int main() {
    return 0;
}
