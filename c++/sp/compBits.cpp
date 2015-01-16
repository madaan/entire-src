//sg
#include<bits/stdc++.h>
using namespace std;
int next_two(int x) {
    int res = 0;
    while(x != 0) {
        res++;
        x = x >> 1;
    }
    return res;
}

int comp(int n) {
    if(n > 0) {
        int np2 = next_two(n);
        int mask = 1 << np2;
        mask = mask - 1;
        return n ^ mask;
    } else {
        return ~n;
    }
}

int main() {
    int n;
    cin >> n;
    cout << comp(n) << "\n";
    return 0;
}
