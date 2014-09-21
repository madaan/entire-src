//sg
#include<cstdio>
#define MAX 100
#define max(a, b) ((a > b) ? a : b)
int main() {
    int arr[MAX];
    int i = 5;
    for(int i = 1; i <= 5; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = arr[1];
    int maxSum = sum;
    for(int i = 2; i <= 5; i++) {
        sum = max(0, sum + arr[i]);
        maxSum = max(sum, maxSum);
    }
    printf("%d\n", maxSum);
    return 0;
}

