//sg
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)
#define swap(a, b) a = a ^ b;b = a ^ b; a = a ^b;
/*
Concept : initialize every element of l to 1, meaning that 
there is atleast an increasing subsequence of size 1. Then starting
from left, you pick an element. For that element, you scan elements to 
the left and pick the one which is less than the chosen element and 
has the maximum value of l. 
*/

int arrmax(int *arr, int N) 
{
    int max = arr[0];
    int j = 1;
    for(j = 1; j < N; j++) {
        if(arr[j] > max) {
            max = arr[j];
        }
    }
    return max;
}


int lis(int *arr, int N) 
{
    int *l = malloc(N * sizeof(int));
    int i = 0;
    for(i = 0; i < N; i++) {
        l[i] = 1;
    }
    int j = 0;
    for(i = 1; i < N; i++) {
        for(j = i -1; j >= 0; j--) {
            if(arr[i] > arr[j]) { 
                l[i] = max(l[i], 1 + l[j]);
            }
        }
    }
    return arrmax(l, N);
}

int reverse(int *arr, int start, int end) 
{
    int i;
    for(i = start; i < (start + (((end - start) + 1) / 2)); i++) {
        swap(arr[i], arr[end - (i - start)]);
    }


}

int rotate(int *arr, int rot, int N) { 
    reverse(arr, 0, rot - 1);
    reverse(arr, rot, N - 1);
    reverse(arr, 0, N - 1);
}
int main() 
{
    int arr[10010];
    int N, t;
    scanf("%d", &t);
    while(t--) { 
    
        scanf("%d", &N);
    
        int i = 0;
        for(i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        int res = 1;
        //for all cyclic permutations
        for(i = 1; i < N; i++) {
            rotate(arr, 1, N);
            res = max(res, lis(arr, N));
        }
        printf("%d\n", res);
        
    }
    return 0;
}
