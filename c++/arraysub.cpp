//sg
#include <stdio.h>

int main() 
{
    int n, k, arr[1000009];
    scanf("%d" , &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);
    int max, max_index;
    max = arr[0];
    max_index = 0;
    for(int i = 1; i < k; i++) {
        if(arr[i] > max) {
           max = arr[i];
           max_index = i;
        }
    }
    printf("%d ", max);
    for(int i = 1; i <= n - k ; i++) { 
        if(max_index == i - 1) { 
            if(arr[i + k - 1] > arr[i - 1]) { 
                max = arr[i + k - 1];
                max_index = i + k - 1;
            } else {
                //now we don't know who might be the largest of the remaining
                max = arr[i];
                max_index = i;
                for(int j = i; j < i + k; j++) { 
                    if(arr[j] > max) {
                        max = arr[j];
                        max_index = j;
                    }
                }
                printf("%d ", max);
            }
        } else if(max > arr[i + k - 1]) {
            printf("%d ", max);
        } else {
            max = arr[i + k - 1];
            max_index = i + k - 1;
            printf("%d ", max);
        }
    }
    printf("\n");
    return 0;
}

