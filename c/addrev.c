//sg
#include <stdio.h>
#include <string.h>
#define swap(a,b) a = a ^ b; b = a ^ b; a = a ^ b;

void reverse(char *str, int l)
{
    int i = 0;
    for(i = 0; i < l / 2 ; i++) {
        swap(str[i], str[l - i - 1]);
    }
}


int main() 
{
    char num1[1000], num2[1000], num3[1000];
    int t;

    scanf("%d", &t);
    char *e;
    while(t--) {
        scanf("%s%s", num1, num2);
        //printf("num1 = %s num2 = %s\n", num1, num2);

        //strip the leading zeroes
        int n1 = atoi(num1);
        int n2 = atoi(num2);
        sprintf(num1, "%d", n1);
        sprintf(num2, "%d", n2);

        int l1 = strlen(num1);
        int l2 = strlen(num2);
        reverse(num1, l1);
        reverse(num2, l2);
        
        //printf("num1 = %s num2 = %s\n", num1, num2);
        n1 = atoi(num1);
        n2 = atoi(num2);
        int n3 = n1 + n2;
        
        sprintf(num3, "%d", n3);
        int l3 = strlen(num3);
        reverse(num3, l3);
        printf("%d\n", atoi(num3));
    }
    return 0;
}
