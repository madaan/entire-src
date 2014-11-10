//sg
#include<cstdio>
#define MAX 1010
int a[MAX], b[MAX], f[MAX];
int main() {
    int n, temp;
    f[0] = a[0] = b[0] = 0;
    f[2] = 5;
    f[1] = 1;
    b[1] = 1;
    b[2] = 1;
    a[1] = 1;
    a[2] = 2;
    for(int i = 3; i < MAX; i++) {
        b[i - 1] = b[i - 3] + f[i - 2];
        a[i - 1] = a[i - 2] + f[i - 2];
        f[i] = f[i - 1] + f[i - 2] + 2 * a[i - 1] + b[i - 1];
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        printf("%d %d\n", i,  f[temp]);
    }
    return 0;
}

