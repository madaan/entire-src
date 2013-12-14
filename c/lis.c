//sg
//this is a different problem. The subsequence in this case 
//has to be increasing
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[100];
    int N;
    scanf("%d", &N);
    int i = 0;
    while(i < N) {
        scanf("%d", (arr + i));
        i++;
    }
    
    int *maxEndingAt = malloc(sizeof(int) * N);

    maxEndingAt[0] = 1;
    for(i = 1; i < N; i++) {
        if(arr[i] > arr[i - 1]) {
            maxEndingAt[i] = maxEndingAt[i - 1] + 1;
        } else {
            maxEndingAt[i] = 1;
        }
    }
    int max = maxEndingAt[0];
    for(i = 1; i < N; i++) {
        if(maxEndingAt[i] > max) {
            max = maxEndingAt[i];
        }
    }
    printf("%d\n", max);
    free(maxEndingAt);

    return 0;
}

