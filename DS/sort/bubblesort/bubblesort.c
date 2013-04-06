//sg
#include<stdio.h>
void bubble(int * a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < (n - i - 1); j++) {
            if (a[j] > a[j + 1]) {
                a[j] = a[j] ^ a[j + 1];
                a[j + 1] = a[j] ^ a[j + 1];
                a[j] = a[j + 1] ^ a[j];
            }
        }
}
int main()
{
    int a[] = {3, 34, 12, 43, 3, 1, 4, 534, 11, 121};
    int i;
    printf("\n");
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    bubble(a, 10);
    printf("\n");
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}
