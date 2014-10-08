//sg
#include<bits/stdc++.h>
using namespace std;
int countInversions(vector<string> &names, int n) {
    
    int inv = 0;
    for(int i = 2; i <= n; i++) {
        int j = i;
        //cout << i << " : " << names[i] << "\n";
        string bu = names[i];
        while(j > 0 && (names[j] < names[j - 1])) {
            names[j].swap(names[j - 1]);
            j--;
        }
        if(j != i) {
            inv++;
            //cout << "swapping " << names[i] << " " << names[j + 1] << "\n";
            names[j] = bu;
        }
    }
    return inv;


}

int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int n;
        cin >> n;
        vector<string> names(n + 1);
        cin.ignore();
        for(int i = 1; i <= n; i++) {
            getline(cin, names[i]);
            //cout << "\n " << i << " : " << names[i] << "\n";
        }
        cout << countInversions(names, n) << "\n";
    }
    return 0;
}
