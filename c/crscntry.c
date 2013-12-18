 //sg
#include <string.h>
#include <stdio.h>
#define max(a, b) ((a > b) ? (a) : (b))
int L[3050][3050];

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

int int_lcs(int *str1, int *str2, int l1, int l2)
{
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

void stripSpaces(char *str) {
    char temp[5000];
    int i, j;
    i = 0;
    while(str[i]) {
        if(str[i] == ' ') { 
            i++;
        } else {
            temp[j] = str[i];
            i++;
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void read_arr(int *arr, int *l) {
    int i = 0, c;
    while(1) {
        scanf("%d", &c);
        if(c == 0) {
            if(i == 0) {
                arr[0] = 0;
                i++;
            }
            break;
        } else {
            arr[i] = c;
        }
        i++;
    }
    *l = i;
}


int main()
{
    int t, max_meet, temp;
    int ang_route[3000], t_route[3000], al, tl;
    scanf("%d", &t);
    while(t--) {
        //read Angena's route
        max_meet = 0;
        read_arr(ang_route, &al);
        while(1) { //read possible routes by tom
            read_arr(t_route, &tl);
            if(tl == 1 && t_route[0] == 0) {
                break;
            }
            max_meet = max(max_meet, int_lcs(ang_route, t_route, al, tl));
        }
        
        printf("%d\n", max_meet);
    }
    return 0;
}
