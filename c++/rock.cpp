//sg
//sg
#include<stdio.h>
#include<cstring>
using namespace std;
int arr[201][201];
int one[201], zero[201];
char ip[201];
#define max(a, b) ((a > b) ? a : b)
int getMin(char ip[], int N) {
    zero[0] = 0;
    one[0] = 0;
    for(int i = 1; i <= N; i++) {
        one[i] = one[i - 1];
        zero[i] = zero[i - 1];
        if(ip[i] == '1') {
            one[i]++;
        } else {
            zero[i]++;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int numOne = one[j] - one[i - 1];
            int numZero = zero[j] - zero[i - 1];
            if(numOne > numZero) {
                arr[i][j] = j - i + 1;
            } else {
                arr[i][j] = -1;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        arr[i][i] = (ip[i] == '1') ? 1 : 0;
    }
    for(int l = 2; l <= N; l++) {
        for(int i = 1; i <= N - l + 1; i++) {
            int j = i + l - 1;
            for(int k = i; k <j; k++) {
                arr[i][j] = max(arr[i][j], arr[i][k] + arr[k + 1][j]);
            }
        }
    }

    //   cout << "l = " << l << endl;
    //printMat(arr, N);
    return arr[1][N];
}

int main() {
    int t;
    scanf("%d", &t);
    char ip[201];
    int N;
    while(t--) {
        char ip1[202];
        ip1[0] = '#';
        ip1[1] = '\0';
        scanf("%d", &N);
        scanf("%s", ip);
        printf("%d\n", getMin(strcat(ip1, ip), N));
    }
    return 0;
}
