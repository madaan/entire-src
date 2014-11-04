//sg
#include<bits/stdc++.h>
using namespace std;
int cnt1[26], cnt2[26];
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 0, l = str1.length(); i < l; i++) {
        cnt1[str1[i] - 97]++;
    }
    for(int i = 0, l = str2.length(); i < l; i++) {
        cnt2[str2[i] - 97]++;
    }
    int res = 0;
    for(int i = 0; i < 26; i++) {
        res += abs(cnt2[i] - cnt1[i]);
    }
    cout << res << "\n";
    return 0;
}
