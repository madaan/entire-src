//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector< int > vals(n, -1);
    for(int i = 0; i < n; i++) cin >> vals[i];
    priority_queue<int> pq;
    sort(vals.begin(), vals.end());
    int sold = 0, res = 0;
    pq.push(vals[n - 1]);
    while(sold < m) {
        int tope = pq.top();
        //cout << "got : " << tope << "\n";
        if(tope == 0) break;
        pq.pop();
        res += tope;
        tope--;
        pq.push(tope);
        sold++;
    }
    cout << res << "\n";
    return 0;
}
    
