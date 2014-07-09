//sg
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main() {
    srand(time(NULL));
    int i = 0;
    printf("1\n1000000 4\n");
    for(i = 0; i < 1000000; i++) {
        int r = rand();
        if(r % 2 == 0) {
            printf("0");
        } else {
            printf("1");
        }
    }
    return 0;
}
        
