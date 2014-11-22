//sg
#include<bits/stdc++.h>
using namespace std;

double last_k_med(vector<double> &allArr, int k) {
    vector<double> tmp;
    for(int i = allArr.size() - 1, pro = 0; pro < k; i--, pro++) {
        tmp.push_back(allArr[i]);
    }
    sort(tmp.begin(), tmp.end());
    if(k % 2) {
        return tmp[k/2];
    } else {
        return tmp[k/2];
    }
}

int main(int argc, char *argv[1]) {
    int k;
    cin >> k;
    double P;
    cin >> P;
    double med;
    double val;
    int added_elements = 0;
    setiosflags(ios::fixed);
    vector<double> allVals;
    while(cin >> val) {
        added_elements++;
        if(added_elements > k) {
            med = last_k_med(allVals, k);
            if(abs(med - val) / med > P) {
                cout << fixed << setprecision(3) << val << "\n";
            }
        }
        allVals.push_back(val);
    }
    return 0;
}
