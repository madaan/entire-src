//sg
#include<cstdio>
#define abs(x) ((x) < 0 ? (x) * -1 : (x))
#define de(x,y) printf("%s = %d\n", y,  x);
//upper cat is cat 1
void checkDia(int mx, int my, int c1x, int c1y, int c2x, int c2y) {
    if(mx - c1x > 0) { //first type of diagonal (i - x, j + x to i + x, j - x)
        int rowDiff = c1y - my;
        int colDiff = mx - c1x;
        if(rowDiff != colDiff) {
            printf("YES\n");
            return;
        }
        if((my - rowDiff != c2y) || (mx + colDiff != c2x)) {
            printf("YES\n");
            return;
        }
        printf("NO\n");
    } else { //second type of diagonal, i - x, j - x to i + x, j + x
        int rowDiff = c1y - my;
        int colDiff = c1x - mx;
        if(rowDiff != colDiff) {
            printf("YES\n");
            return;
        }
        if((my - rowDiff != c2y) || (mx - colDiff != c2x)) {
            printf("YES\n");
            return;
        }
        printf("NO\n");
    }
}

    
int main() {
    int m, n;
    int k;
    int mx, my, c1x, c1y, c2x, c2y;
    scanf("%d%d%d", &n, &m, &k);
    while(k--) {
        scanf("%d%d%d%d%d%d", &my, &mx, &c1y, &c1x, &c2y, &c2x);
        if(my == c1y && mx == c1x || my == c2y && mx == c2x) {
            printf("NO\n");
            continue;
        }
        if((my >= c1y && my >= c2y) || (my <= c1y && my <= c2y))  {
            printf("YES\n");
            continue;
        }
        if((mx >= c1x && mx >= c2x) || (mx <= c1x && mx <= c2x)) {
            printf("YES\n");
            continue;
        }
        if(c1y > c2y) {
            checkDia(mx, my, c1x, c1y, c2x, c2y);
        } else {
            checkDia(mx, my, c2x, c2y, c1x, c1y);
        }

    }
    return 0;
}
    
