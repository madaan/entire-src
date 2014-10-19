#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 350000
ll dp[100];
vector< int > primes;

//returns the last index i where x <= primes[i]
int getprimebefore(int x) {

    int left = 0;
    int right = 1;
    while(primes[right] < x) {
        left = right;
        right = right * 2;
    }
    while((right - left) > 1) {
        int mid = left + (right - left) / 2;
        //cout << "primes[" << mid << "] = " << primes[mid] << "\n";
        if(primes[mid] >= x) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}




int main() {
    dp[0] = 0;
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;
    for(int i = 5; i < 100; i++) {
        dp[i] = dp[i - 4] + dp[i - 1];
    }
    vector< bool >  prime(MAX, true);
    prime[0] = prime[1] = false;
    int maxn = sqrt(MAX);
    for(int i = 2; i < maxn; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= MAX; j+= i) {
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i < MAX; i++) {
        if(prime[i]) {
            primes.push_back(i);
        }
    }
    //cout << primes[primes.size() - 1] << "\n";
    /*
    for(int i = 0; i < 10; i++) {
        cout << primes[i] << " ";
    }
    cout << "\n";
    */
        

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        //cout << dp[n] << "\n";
        int res = getprimebefore(dp[n]);
        //cout << "res : " << res << "\n";
        if(res != 0) res++;
        if(prime[dp[n]]) res++;
        cout << res << "\n";
    }
    return 0;
}


