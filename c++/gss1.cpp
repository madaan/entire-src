//sg
#include<cstdio>
#define max(a, b) ((a > b) ? a : b)
#define MAX 50005
int arr[MAX];
int getMax(int x, int y) {
    int sum = arr[x];
    int maxSum = sum;
    for(int i = 2; i <= y; i++) {
        sum = max(arr[i], sum + arr[i]);
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
int main() {
    int n, m;
    int x, y;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", getMax(x, y));
    }
    return 0;
}
