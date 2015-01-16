//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    //res = 1000000000;
    //for(int i = 0; i < n; i+=m) {
    //res = min(res, (i / m) * b + a * (n - 1));
    int pa = ((n % m) * a + (n/m) * b);
    int pb = ((n / m) + 1) * b;
    int pc = n * a;
    printf("%d\n", min(pa, min(pb, pc)));
    return 0;
}
