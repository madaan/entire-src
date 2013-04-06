#include "partition.h"
void qs(int a[], int p, int r)
{
    int q, i;
    printf("\nRunning qs(a,%d,%d)", p, r);
    if (p < r) {
        q = partition(a, p, r);
        printf("\nPartitioning at %d", q);
        puts(" ");
        for (i = 0; i < 5; i++) {
            printf("%d  ", a[i]);
        }
        qs(a, p, q - 1);
        qs(a, q + 1, r);

    }
}
main()
{
    int a[5], i;
    for (i = 0; i < 5; i++) {
        printf("Enter %d element :", i);
        scanf("%d", &a[i]);
    }
    qs(a, 0, 4);
    puts(" ");
    for (i = 0; i < 5; i++) {
        printf("%d  ", a[i]);
    }
    puts(" ");
}
