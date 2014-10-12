//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r, t;
ll val(ll k) {
    return 2l * k * k + (2l * r - 1l) * k;
}

ll getval() {
    ll left = 0, right = 1;
    //obtain the range
    while(val(right) <= t) {
        left = right;
        right = right * 2;
        //cout << left << " " << right << "\n";
    }
    
    while(right - left > 1) {
        //cout << left << " " << right << "\n";
        ll mid = left + ((right - left) / 2l);
            //cout << val(mid) << "\n";
        //cout << "l = " << l << "\nmid = " << mid << "\nr = " << r << "val = " << val(mid) << "\n\n";
        if(val(mid) > t) {
            right = mid;
        } else {
            left = mid;
        }
    }
    //l is the first point where we become > 
    return left;
}

int main() {
    int cases;
    cin >> cases;
    for(int qq = 1; qq <= cases; qq++) {
        printf("Case #%d: ", qq);
        cin >> r >> t;
        cout << getval() << "\n";
    }
    return 0;
}
