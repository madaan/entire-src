//sg
#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
int maze[MAX][MAX];
int dp[MAX][MAX];
int from[MAX][MAX];
int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
         printf("Case #%d: ", tt);
         int n;
         cin >> n;
         vector<int> city(501, 0);
         int sa, sb;
         for(int i = 0; i < n; i++) {
             cin >> sa >> sb;
             //cout << sa << " " << sb << "\n";
             for(int j = sa; j <= sb; j++) {
                 city[j]++;
             }
         }
         int p;
         cin >> p;
         for(int k = 0; k < p; k++) {
             cin >> sa;
             //cout << sa << "\n";
             cout << city[sa] << " ";
         }
         cout << "\n";
    }
    return 0;
}

 
