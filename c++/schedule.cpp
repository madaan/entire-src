//sg
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

bool orlp(pi x, pi y) {
    pi a, b;
    if(x.first < y.first) {
        a = x;
        b = y;
    } else if(y.first < x.first) {
        a = y;
        b = x;
    } else {
        return true;
    }
    if(a.second < b.first) {
        return false;
    }
    return true;
}


void disp(pi a) {
    cout << "( " << a.first << ", " << a.second << ")\n";
}

int main() {
    int p, q, l, r, a, b;

    cin >> p >> q >> l >> r;
    vector<pi> z, x;
    for(int i = 0; i < p; i++) {
        cin >> a >> b;
        z.push_back(pi(a, b));
    }
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        x.push_back(pi(a, b));
    }

    long long res = 0;
    for(int t = l; t <=r; t++) {
        for(int i = 0; i < x.size(); i++) {
            pi x_sftd = pi(x[i].first + t, x[i].second + t);
            int j = 0;
           for(j = 0; j < z.size(); j++) {
               if(orlp(x_sftd, z[j])) {
                   res++;
                   break;
               }
           }
           if(j < z.size()) {
               break;
           }
        }
    }
    cout << res << "\n";
    return 0;
}

    


