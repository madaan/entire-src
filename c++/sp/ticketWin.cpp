//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> pq;
    int n, m, tmp;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }
    int res = 0;
    for(int i = 0; i < m; i++) {
        int te = pq.top();
        pq.pop();
        pq.push(te - 1);
        res += te;
    }
    cout << res << "\n";
    return 0;
}
