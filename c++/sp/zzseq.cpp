//sg
#include<bits/stdc++.h>
using namespace std;

#define UP 1
#define DN 0

int a[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
int dp[100][2];
int l;

int ans(int i, int dir) {
    if(dir != -1 && dp[i][dir] != -1) {
        return dp[i][dir];
    }
    if(i == l - 1) {
        return 1;
    }
    int res = 0;
    for(int j = i + 1; j < l; j++) {
        int newDir;
        if(a[j] == a[i]) {
            continue;
        } else if(a[j] > a[i]) {
            newDir = UP;
        } else {
            newDir = DN;
        }
        if(dir == -1 || newDir ^ dir) {
            res = max(res, ans(j, newDir));
        }
    }
    return dp[i][dir] = res + 1;
}

int main() {
    memset(dp, -1, sizeof(dp));
    l = sizeof(a) / sizeof(a[0]);
    int res = 0;
    for(int i = 0; i < l; i++) {
        res = max(res, ans(i, -1));
    }
    cout << res << "\n";
    return 0;
}
