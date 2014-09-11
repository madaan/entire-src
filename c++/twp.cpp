//sg
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int partLen = n / 4;
    int colEnd = n - partLen + 1;
    int colStart = 1;
    printf("1   ");
    for(int i = 0; i < partLen; i++) {
        printf("%-4d ", n - i);
    }
    int numSpaces = (partLen - 1) * 5;

    for(int i = 0; i < partLen - 1; i++) {
        printf("\n%-4d ", ++colStart);
        for(int j = 0; j < numSpaces; j++) {
            printf(" ");
        }
        printf("%-4d", --colEnd);
    }

    printf("\n");
    //Take care of the last row
    for(int i = 0; i <= partLen; i++) {
        printf("%-4d ", ++colStart);
    }
    printf("\n");
    return 0;
}
    

