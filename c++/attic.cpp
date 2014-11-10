//sg
#include <stdio.h>
char attic[1000000];
int desc[1000000];
int main()
{
    int pjl; //previous jump length
    pjl = 1;
    int i = 0, jumpLength, nd, T;
    scanf("%d", &T);
    while(T--) {
        i = 0;
        scanf("%s", attic);
        nd = 0;
        pjl = 1;
        while(attic[i]) {
            jumpLength = 0;
            while(attic[i] == '#') {
                i++;
            }
            while(attic[i] == '.') {
                jumpLength++;
                i++;
            }
            jumpLength++;
            if(jumpLength > pjl) {
                nd++;
                pjl = jumpLength;
            }
        }
        printf("%d\n", nd);
    }
    return 0;
}
