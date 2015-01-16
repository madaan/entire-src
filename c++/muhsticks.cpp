//sg
#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main() {
    vector<int> hts;
    int tmp;
    for(int i = 0; i < 6; i++) {
        cin >> tmp;
        cnt[tmp]++;
        hts.push_back(tmp);
    }
    int leg = -1;
    for(int i = 1; i<= 9; i++) {
        if(cnt[i] >= 4) {
            leg = i;
            break;
        }
    }
    if(leg == -1) {
        cout << "Alien\n";
        return 0;
    }
    int picked = 0;
    for(int i = 0; i < 6 && picked < 4; i++) {
        if(hts[i] == leg) {
            hts[i] = 0;
            picked++;
        }
    }
    sort(hts.begin(), hts.end());
    int o1 = hts[4];
    int o2 = hts[5];
    if(o1 == o2) {
        cout << "Elephant\n";
    } else {
        cout << "Bear\n";
    }
    return 0;
}
