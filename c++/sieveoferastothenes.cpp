//sg
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char * argv[]) {
    if(argc != 2) {
        printf("Usage : $./sieve N\n");
        return 0;
    }
    int n = atoi(argv[1]);
    bool * mark = new bool[n];
    for(int i = 0; i <= n; i++) {
        mark[i] = true;
    }
    mark[1] = false;
    for(int i = 2; i <= n; i++) {
        if(mark[i]) {
            for(int k = i * i; k <= n; k += i) {
                mark[k] = false;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(mark[i]) {
            printf("%d ",i);
        }

    }
    printf("\n");
    return 0;
}
