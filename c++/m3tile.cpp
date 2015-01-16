//sg
#include<cstdio>
#define MAX 100
int f[MAX], g[MAX];
int main() {
    f[0] = 1;
    f[1] = 0;
    g[0] = 0;
    g[1] = 1;
    for(int i = 2; i < MAX; i++) {
        if(i % 2 != 0) {
            f[i] = 0;
        } else {
            f[i] = f[i - 2] + 2 * g[i - 1];
        }
        g[i] = f[i - 1] + g[i - 2];
    }
    int temp;
    while(true) {
        scanf("%d", &temp);
        if(temp == -1) {
            break;
        }
        printf("%d\n", f[temp]);
    }
    return 0;
}
