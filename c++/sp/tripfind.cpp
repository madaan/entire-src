//sg
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, sqrtn;

bool check(ll a, ll b, ll c) {
    return a * a + b * b + c * c <= n;
}

ll findf(ll a, ll b) {
    ll left = 0, right = 1;
    
    while(check(a, b, right)) {
        left = right;
        right = right * 8;
    }

    while(right - left > 1) {
        ll mid = (left + right) / 2;
        if(check(a, b, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

bool equal(ll a, ll b, ll c) {
    //printf("check : a = %lld, b = %lld, c = %lld\n", a, b, c);
    bool res = ((a * a) + (b * b) + (c * c))== n;
    //if(res)
    //printf("a = %lld, b = %lld, c = %lld\n", a, b, c);
    return res;
}



int main() {
    cin >> n;
    sqrtn = sqrtl(n);
    for(ll a = 0; a < sqrtn; a++) {
        for(ll b = a; b < sqrtn; b++) {
            ll c = findf(a, b);
            //printf("a = %lld, b = %lld, c = %lld\n", a, b, c);
            if(equal(a, b, c)) {
                printf("%lld, %lld, %lld\n", a, b, c);
            }
        }
    }
    return 0;
}
