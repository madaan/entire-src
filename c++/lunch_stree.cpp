//sg
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MAX 150010
ll dp[MAX];
ll ans[MAX];
const ll MOD = 1000000007l;
int k;
ll mod(ll a, ll b) {
    return (a % b + b) % b;
}
ll a[131072];
void fill() {
    a[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        a[i] = a[i - 1];
        if((i - k) >= 0) {
            a[i] = (a[i] + a[i - k]) % MOD;
        }
    }
}
ll t[131072][18];
int N, n;
void setvals(int nn) {
    n = ceil(log(nn)/log(2));
    N = pow(2, n);
}
ll f(ll a, ll b)
{
    return (a + b) % MOD;
}
void init() {
    for (int x = 0; x < N; x++)
        t[x][0] = a[x];
    for (int y = 1; y <= n; y++)
        for (int x = 0; x < N; x+=(1<<y))
            t[x][y] = f(t[x][y-1], t[x+(1<<(y-1))][y-1]);
}
void set(int x, int v) {
    t[x][0] = a[x] = v;
    for (int y = 1; y <= n; y++) {
        int xx = x-(x&((1<<y)-1));
        t[xx][y] = f(t[xx][y-1], t[xx+(1<<(y-1))][y-1]);
    }
}
int get(int i, int j) {
    int res = 0, h = 0;
    j++;
    while (i+(1<<h) <= j) {
        while ((i&((1<<(h+1))-1)) == 0 && i+(1<<(h+1)) <= j) h++;
        res = f(res, t[i][h]);
        i += (1<<h);
    }
    while (i < j) {
        while (i+(1<<h) > j) h--;
        res = f(res, t[i][h]);
        i += (1<<h);
    }
    return res;
}
int main() {
    int t, a, b;
    n = MAX - 1;
    cin >> t >> k;
    fill();
    setvals(100000l);
    init();
    for(int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << get(a, b) << "\n";
    }
    return 0;
}
