#include"partition.h"
//for an array of 10 elements
//p=0
//q=9
void exchange1(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int partition(int * a, int p, int q)
{
    int i, j, key;
    i = p;
    key = a[p];
    for (j = p + 1; j <= q; j++) {
        if (a[j] <= key) {
            i++;
            printf("\nExchanging: %d ,%d", a[i], a[j]);
            if (a[i] != a[j]) {
                exchange(a[i], a[j]);
            }
#ifdef debug
            printf("\n After Exchanging: %d ,%d", a[i], a[j]);
#endif
        }

    }
    printf("\nExchanging: %d ,%d", a[i], a[p]);
    if (a[i] != a[p]) {
        exchange(a[i], a[p]);
    }
#ifdef debug
    printf("\n After Exchanging: %d ,%d", a[i], a[p]);
#endif
    return i;
}
