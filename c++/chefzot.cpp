//sg
#include<stdio.h>
int main() {
    int mnz = 0, nz = 0, temp;
    int n;
    scanf("%d", &n);
    while(n) {
        nz = 0;
        while((n > 0) && true) {
            scanf("%d", &temp);
            n--;
            if(temp == 0) {
                break;
            }
            nz++;
        }
        if(mnz < nz) {
            mnz = nz;
        }
    }
    printf("%d\n", mnz);
    return 0;
}

