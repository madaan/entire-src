//sg
#include<bits/stdc++.h>
#define MAX 100009
int n, m;
int mod(int a, int n) {
    int r = (a % n + (n)) % (n);
    if(r == 0) return n;
    return r;
}
void rev(int A[MAX], int l, int r) {
    int mid = l + (r - l + 1) / 2;
    for(int i = l, j = r; i < mid; i++,j--) {
        A[i] ^= A[j];
        A[j] ^= A[i];
        A[i] ^= A[j];
    }
}
void left_shift(int A[MAX], int units) {
    rev(A, 1, units);
    rev(A, units + 1, n);
    rev(A, 1, n);
}
void right_shift(int A[MAX], int units) {
    rev(A, 1,  n - units);
    rev(A, n - units + 1, n);
    rev(A, 1, n);
}

void shift(int A[MAX], int units) {
    if(units < 0) {
        left_shift(A, -units);
    } else if(units > 0) {
        right_shift(A, units);
    }
}
int main() {
    int A[MAX];
    int rot = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    char q;
    int d;
    getchar();
    for(int i = 1; i <= m; i++) {
        scanf("%c%d", &q, &d);
        getchar();
        //std::cin >> q >> d;
        if(q == 'A') {
            rot -= d;
        } else if(q == 'C') {
            rot += d;
        } else {
            //shift(A, rot);
            //rot = 0;
            //printf("rot = %d, pos = %d\n", rot, mod(d + rot, n));
            printf("%d\n", A[mod(d + rot, n)]);
        }
    }
    return 0;
}
