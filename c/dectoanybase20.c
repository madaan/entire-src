//sg
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[]) {
    char  digits[] = "0123456789ABCDEFGHIJ";
    if(argc != 3) {
        printf("Usage : $./basec NUMBER_10 TARGET_BASE\n");
        return 0;
        }
    
    int n = atoi(argv[1]);
    int base = atoi(argv[2]);
    char res[1000];
    int i = 0;
    while( argv[1][i] ) {
        res[i++] = digits[n % base];
        
        n = n / base;
    }
   
    while(i >= 0) {
    printf("%c", res[--i]);
    }
    printf("\n");
    return 0;
}

