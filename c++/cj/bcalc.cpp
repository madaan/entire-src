//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000009
typedef long long ll;
ll dp[MAX];
bool on[10];
string to_string(int num) {
    ostringstream temp;
    temp << num;
    return temp.str();
}
int canMake(int y) {
    string num = to_string(y);
    //cout << "checking  : " << num;
    for(int i = 0; num[i]; i++) {
        if(!on[num[i] - 48]) {
            //cout << " can't find : " << (num[i] - 48) << "\n";
            return -1;
        }
    }
    //cout << " : " << num.length() << "\n";
    return num.length();
}
//solution for small input
int res(int x, int d) {
    //cout << x << ", " << d << "\n";
    int l = canMake(x);
    if(l != -1) {
        return l + to_string(d).length() + 1;
    }
    int ans = 1000;
    for(int i = 0; i < 10; i++) {
        if(on[i]) {
            if(i > 1 && (x % i == 0) && ((x / i) > 1)) {
                ans = min(ans, res(x / i, i));
            }
            int hd = d * 10 + i;
            if((x % hd == 0) && ((x / hd) > 1)) {
                ans = min(ans, res(x / hd, hd));
            }
        }
    }
    return ans + to_string(d).length() + 1;
}
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        int x;
        for(int i = 0; i < 10; i++) {
            cin >> x;
            on[i] = false;
            on[i] = (x == 1) ? true : false;
        }
        cin >> x;
        int l = canMake(x);
        if(l != -1) {
            cout << l + 1 << "\n";
            continue;
        }
        int ans = 1000;
        for(int i = 1; i < 10; i++) {
            if(on[i]) {
                if((x % i == 0) && (x / i) > 1) {
                    ans = min(ans, res(x / i, i));
                }
            }
        }
        if(ans == 1000) {
            cout << "Impossible\n";
        } else {
            cout << ans + 1 << "\n";
        }
    }
    return 0;
}
