//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[] = {1,2,3,4,5};
    int b[] = {5,4,3,2,1};
    vector< pair<int, int> > pairVec;
    for(int i = 0; i < 5; i++) {
        pairVec.push_back(pair<int, int>(b[i], a[i]));
    }
    sort(pairVec.begin(), pairVec.end());
    for(int i = 0; i < 5; i++) {
        a[i] = pairVec[i].second;
        b[i] = pairVec[i].first;
    }
    for(int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }
    return 0;
}


