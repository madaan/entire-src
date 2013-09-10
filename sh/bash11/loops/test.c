//sg
#include <stdio.h>
int main() {
    int i, j, k;
    for(i = 1;i <= 15; i++)
        for(j = 1;j <= 15; j++)
            for(k = 1;k <= 15; k++) {
                if(i != j && i != k && k != j)
                printf("\n(%d, %d, %d)", i, j, k);
            }
    return 0;
}

