//sg
#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int main() {
    vector< bool > isPrime(600, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < 600; i++) {
        if(isPrime[i]) for(int j = i * 2; j < 600; j += i) {
            isPrime[j] = false;
        }
    }
    vector< ll > res(550);
    vector< ll > ans(550);
    res[1] = 0;
    res[2] = 1;
    res[3] = 2;
    for(int i = 4; i < 550; i++) {
        if(isPrime[i]) {
            res[i] = res[i - 1] + res[i - 2];
        } else {
            res[i] = res[i - 1];
        }
    }
    ans[0] = 0;
    for(int i = 1; i < 550; i++) {
        ans[i] = res[i] + ans[i - 1];
    }
    int n;
    cin >> n;
    cout << ans[n] << "\n";
    return 0;
}
