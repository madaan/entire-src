//sg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll temp;
    ll prev = 0, curr, pc = 0;
    vector< ll > minf(n + 1, 0);
    vector< ll > arr(n + 1, 0);
    stack<ll> st;
    st.push(1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 2; i <= n; i++) {
        if(arr[i] < arr[i - 1]) {
            st.push(i);
        } else {
            while(!st.empty()) {
                minf[st.top()] = i - st.top() - 1;
                st.pop();
            }
            st.push(i);
        }
    }
     while(!st.empty()) {
        minf[st.top()] = n - st.top();
        st.pop();
    }
    prev = minf[1] + 1;
    ans += prev;
    /*
    for(int i = 1; i <= n; i++) {
        cout << minf[i] << " ";
    }
    cout << "\n";
    */
    for(int i = 2; i <= n; i++) {
        if(arr[i] > arr[i - 1]) {
            curr = max(prev +  1, minf[i] + 1);
        } else {
            curr = minf[i] + 1;
        }
        ans += curr;
        prev = curr;
    }
    cout << ans << "\n";
    return 0;
}
