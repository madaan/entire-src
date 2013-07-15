//sg
#include <stdio.h>
#include <string.h>
int main(int a1, char *a[])
{
    int l = strlen(a[1]);
    int i, s;
    for(s = 0; s < 26; s++) {
    for(i = 0; i < l; i++) {
        printf("%c", (a[1][i] - 97 + s) % 26 + 97);
    }
    printf("\n");
    }
return 0;
}
