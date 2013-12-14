//sg
#include <stdio.h>
#include <string.h>
#define max(a, b)((a > b) ? (a) : (b))


int L[1050][1050];
int s[1050][1050];
int lcs(char *str1, char *str2)
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int i, j;


    for(i = 0; i <= l1; i++) {
        for(j = 0; j <= l2; j++) {
            L[i][j] = 0;
        }
    }
    for(i = 1; i <= l1; i++) { //for all the rows
        for(j = 1; j <= l2; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                L[i][j] = 1 + L[i-1][j-1];
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[l1][l2];
}

int chunked_lcs(char str1[], char str2[], int K) 
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int i, j;

    for(i = 0; i <= l1; i++) {
        for(j = 0; j <= l2; j++) {
            L[i][j] = 0;
        }
    }
    int offset = 0;
    for(i = 1; i <= l1; i++) { //for all the rows
        for(j = 1; j <= l2; j++) {
            //equality loop
            offset = 0;
            while(str1[i - 1 + offset] && str2[j - 1 + offset] && (str1[i - 1 + offset] == str2[j - 1 + offset])) {
                //L[i + offset - 1][j + offset - 1] = max(offset + L[i-1][j-1], L[i + offset - 1][j + offset - 1]);
                offset++;
            }
            if(offset >= K) { //condition satisfied 
                L[i][j] = max(L[i-1][j], L[i][j-1]);
                L[i + offset - 1][j + offset - 1] = max(offset + L[i-1][j-1], L[i + offset - 1][j + offset - 1]);
                //printf("L[%d][%d] = %d\n", i + offset - 1, j + offset - 1, L[i + offset - 1][j + offset - 1] );
                //need to update i and j as well
                //i = i + offset - 1;
                //j = j + offset - 1;
            } else {
                if(L[i][j] == 0) {
                   L[i][j] =  max(L[i-1][j], L[i][j-1]);
                } else {
                    L[i][j] = max(L[i][j], max(L[i-1][j], L[i][j-1]));
                }
            }
        }
    }
    return L[l1][l2];
}

int main()
{
    int K;
    char str1[1050], str2[1050];
    while(1) {
        scanf("%d", &K);
        if(K == 0) {
            break;
        }
        scanf("%s%s", str1, str2);
        printf("%d\n", chunked_lcs(str1, str2, K));
    }
    return 0;
}

