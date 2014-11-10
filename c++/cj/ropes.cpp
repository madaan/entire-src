//sg
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int n;
        cin >> n;
        int a, b;
        vector<pi> pts;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            pts.push_back(pi(a, b));
        }
        sort(pts.begin(), pts.end());
        ll res = 0;
        set<int> ignored;
        for(int i = 0; i < pts.size(); i++) {
            int pt_a = pts[i].first;
            int pt_b = pts[i].second;
            for(int j = i; j < pts.size(); j++) {
                if(i != j) {
                    if(pts[j].first < pt_a && pts[j].second > pt_b) {
                        res++;
                    } else if(pts[j].first > pt_a && pts[j].second < pt_b) {
                        res++;
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
