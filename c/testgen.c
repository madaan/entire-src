//sg
#include <stdio.h>
#include <stdlib.h>
typedef long long LL;
int main(int argc, char * argv[])
{
    int t = atoi(argv[1]);
    int ot = t;
    printf("%d\n", t);
    LL vals;
    while(t--) {
        vals = rand() % 1000000000;
        if(t == ((2 * ot) / 3)) {
            printf("2\n");
        }
        else if(t == (ot / 2)) {
            printf("2\n");
        }
        else if(t == ot / 3) {
            printf("2\n");
        }
        else {
        printf("1 %lld\n", vals);
        }
    }
    return 0;
}

