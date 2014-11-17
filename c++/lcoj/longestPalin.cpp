//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int sl = s.length();

        bool pali[1001][1001];
        memset(pali, 0, sizeof(pali));
        for(int i = 0; i < sl; i++) {
            pali[i][i] = true;
        }
        int an_beg = 0;
        int ans_len = 1;
        for(int i = 0; i < sl - 1; i++) {
            pali[i][i + 1] = (s[i] == s[i + 1]);
            if(pali[i][i + 1]) {
                an_beg = i;
                ans_len = 2;
            }
        }
        
        for(int k = 3; k <= sl; k++) {
            for(int j = 0; j < sl - k + 1; j++) {
                pali[j][j + k - 1] = (s[j] == s[j + k - 1]) && (pali[j + 1][j + k - 2]);
                if(pali[j][j + k - 1]) {
                    if(k > ans_len) {
                        an_beg = j;
                        ans_len = k;
                    }
                }
            }
        }
        return s.substr(an_beg, ans_len);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.longestPalindrome(argv[1]) << "\n";
    return 0;
}
