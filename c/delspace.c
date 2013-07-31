//sg
#include <stdio.h>
int main()
{
    char str[] = "my spaced string";
    char res[100];
    int i  = 0, j = 0;
    while(str[i])
    {

        if(str[i] == ' ') {
            i++;
            continue;
        } else {
            res[j] = str[i];
            j++;
            i++;
        }
    }
    printf("\n");

    return 0;
}
