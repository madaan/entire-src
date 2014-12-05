//sg
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) {
    return b * (((a - b) & (1 << 31)) >> 31) + a * (((b - a) & (1 << 31)) >> 31);
}

int main() {
    cout << -max(1,2) << "\n";
    return 0;
}
