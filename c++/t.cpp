#include<stdio.h>
int main() {
    static int a[][2][3]= {0,1,2,3,4,5,6,7,8,9,10,11,12};
    int i=-1;
    int d;
    int b[] = {1, 2};
    int c = b[-2];
    printf("%d\n", c);
    d=a[i++][++i][++i];
    printf("%d",d);
    return 0;
}
