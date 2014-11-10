//sg
#include<bits/stdc++.h>
using namespace std;
int t[131072][18];
int a[131072];
int N, n;
void setvals(int nn) {
    n = ceil(log(nn)/log(2));
    N = pow(2, n);
}
int f(int a, int b)
{
    if ( b == 0 )
        return a ;
    return f( b, a%b ) ;
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
int nn;
typedef long long ll;
//first point where gcd <= q
int binL(int i, int q) {
    int l = i, r = nn;
    while(l < r) {
        int mid = (l + r) / 2;
        if(get(i, mid) <= q) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}
//first point where gcd < q
int binR(int i, int q) {
    int l = i, r = nn;
    while(l < r) {
        int mid = (l + r) / 2;
        if(get(i, mid) < q) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}
ll fastsolve(int q) {
    ll res = 0;
    for(int i = 0; i < nn; i++) {
        if(a[i] < q) {
            continue;
        }
        int fs = binL(i, q);
        if(get(i, fs) != q) {
            continue;
        } else {
            int rs = binR(i, q);
            res += (rs - fs);
        }
    }
    return res;
}
ll solve(int q) {
    ll res = 0;
    for(int i = 0; i < nn; i++) {
        if(a[i] < q) {
            continue;
        }
        for(int j = i; j < nn; j++) {
            int rij = get(i, j);
            if(rij < q) {
                break;
            } else if(rij == q) {
                res++;
            }
        }
    }
    return res;
}
int main() {
    cin >> nn;
    for(int i = 0; i < nn; i++) {
        scanf("%d", &a[i]);
    }
    setvals(nn);
    init();
    int q, temp;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> temp;
        cout << fastsolve(temp) << "\n";
    }
    return 0;
}
