//sg
//finding the longest arithmetic progression length
#include <stdio.h>
#define max(a, b) ((a > b) ? a : b)
#define MAX 100

//first we will write a function that determines whether there are
//3 numbers in the array that are in AP

int hasAvgTerms(int *arr, int N)
{
    int m, l, r, lhs, rhs;
    for(m = 1; m < N - 1; m++) { //from first till the second last term
        for(l = 0, r = N -1; l < m, r > m;) {
            
            rhs = arr[l] + arr[r]; //defition of Arithmetic mean
            lhs = arr[m] * 2;

            if(lhs == rhs) {
                return 1;
            } else if(lhs < rhs) { //need to reduce weight from right
                r--;
            } else {
                l++;
            }
        }
    }
    return 0;
}

int L[MAX][MAX];

int llap(int *arr, int N)
{
    int l, r, lhs, rhs, j, i;
    int res = -1;
    for(i = 0; i < N;i++) {
        L[i][N-1] = 2; //ap formed with second term as the last term can only have 2 elements
    }
    for(j = N - 2; j >= 1; j--) { //fix a column
        for(l = 0, r = N - 1; l < j, r > j;) {
            
            rhs = arr[l] + arr[r]; //defition of Arithmetic mean
            lhs = arr[j] * 2;

            if(lhs == rhs) {
                L[l][j] = L[j][r] + 1;
                l++;
                r--;
                res = max(res, L[l][j]);
            } else if(lhs < rhs) { //need to reduce weight from right
                r--;
            } else {
                L[l][j] = 2; //with first two terms arr[l] and arr[j], AP is not possible. Thus update.
                l++;
            }
        }
    }

    
    return res;
}

int pmat(int arr[][100], int N) 
{
    int i, j;
    int max = 0;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    return max;
}

int main(int argc, char *argv[]) 
{
    
    int set1[] = {1, 7, 10, 13, 14, 19};
    int n1 = sizeof(set1)/sizeof(set1[0]);

    pmat(L, n1);
    printf("Answer : %d\n", llap(set1, n1));
    pmat(L, n1);
    return 0;
}
