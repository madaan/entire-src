//sg
#include <stdio.h>
#include <string.h>

#define max(a, b)((a > b) ? (a) : (b))
#define swap(a,b) a = a ^ b; b = a  ^ b; a = a ^ b;

int L[6200][6200];
int lcs(char *str1, char *str2)
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int i, j;


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

void reverse(char *w, int si, int ei) {
    int i, j;
    for(i  = si; i  < si + ((ei - si + 1) / 2); i++) {
        swap(w[i], w[ei - (i - si)]);
    }
}

int main()
{
    int t, l, lcs_len;
    char w[10000], wr[10000];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", w);
        strcpy(wr, w);
        l = strlen(w);
        reverse(wr, 0, l - 1);
        lcs_len = lcs(w, wr);
        printf("%d\n", l -  lcs_len);
    }
    return 0;
}
