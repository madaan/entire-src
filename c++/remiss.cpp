//sg
#include <stdio.h>
#define max(a, b) (a > b ? a : b)
int main()
{
    int T, a, b;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &a, &b);
        printf("%d %d\n", max(a, b), a + b);
    }
    return 0;
}
