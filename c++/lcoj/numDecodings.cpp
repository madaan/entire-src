//sg
#include<bits/stdc++.h>
using namespace std;

 int numDecodings(string s) {
     if(s.empty() || s[0] == '0') {
         return 0;
     }
     
     int *dp = new int[s.length() + 1];
     dp[0] = 1;
     int x = stoi(s.substr(0, 2));
     if(s[1] == '0') {
         if(s[0] != '1' && s[0] != '2') {
             return 0;
         }
         dp[1] = 1;
     }else if(x < 27) {
         dp[1] = 2;
     } else {
         dp[1] = 1;
     }
     for(int i = 2, l = s.length(); i < l; i++) {
        int tmp = stoi(s.substr(i - 1, 2));
        if(s[i] == '0') {
            if(s[i - 1] != '1' && s[i - 1] != '2') {
                return 0;
            }
            dp[i] = dp[i - 2];
        }else if(tmp < 27 && s[i - 1] != '0') {
            dp[i] = dp[i - 1] + dp[i - 2];
        } else {
            dp[i] = dp[i - 1];
        }
    }
     return dp[s.length() - 1];
 }


int main() {
    cout << numDecodings(string("101")) << "\n";
    return 0;
}
