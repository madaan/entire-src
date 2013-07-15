//sg
#include <stdio.h>
int main()
{
    int i, j, k;
    int x[][2] = {{1, 2}, {3, 4}, {5, 6}};
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            if(j == i) {
                continue;
            }

            for(k = 0; k < 10; k++) {
                if((k == i) || (k == j)) {
                    continue;
                } 
                printf("(%d, %d, %d)\n", i, j, k);
            }
        }
    }
    return 0;
}
