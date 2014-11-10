//sg
#include <stdio.h>
int tester(int *a, int m, int n) {
}
int main()
{
    int m = 4, n;
    n = 3;
    int a[m][n];
    tester(&a[0][0], m, n);
    return 0;
}
