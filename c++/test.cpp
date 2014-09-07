//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[] = {0, 5, 4, 3, 2, 1};
    sort(a + 1, a + 3 + 1);
    for(int i  = 1; i <= 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

