//sg
#include<stdio.h>

int main() {
    enum dir {UPR, UPL, DOWNR, DOWNL, OVER};
    int t;
    int n, m, x, y;
    scanf("%d", &t);
    int path[4];
    while(t--) {
        scanf("%d%d", &n, &m);
        scanf("%d%d", &x, &y);
        path[UPR] = (x - 1) + (m - y);
        path[UPL] = (x - 1) + (y - 1);
        path[DOWNL] = (n - x) + (y - 1);
        path[DOWNR] = (n - x) + (m - y);
        int max = 0;
        for(int p = UPR; p != OVER; p++) {
            if(path[p] > max) {
                max = path[p];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}

