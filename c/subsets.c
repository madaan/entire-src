//sg
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void subset(char arr[], int mark)
{   

    if(mark == strlen(arr)) {
        //remove spaces
        
        char *temp = malloc(strlen(arr));
        int i = 0, j = 0;
        while(arr[i]) {
            while(arr[i] == ' ') {
                i++;
            }
            temp[j++] = arr[i++];
        }
        temp[j] = '\0';

        i = 0;
        if(temp[0] == '\0') { 
            printf("{}\n");
            return;
        }
        printf("{");
        while(temp[i + 1]) {  
        printf("%c, ", temp[i]);
        i++;
        }
        printf("%c}\n", temp[i]);

        free(temp);
        return ;
    }
    subset(arr, mark + 1);
    char bu = arr[mark];
    arr[mark] = ' ';
    subset(arr, mark + 1);
    arr[mark] = bu;
}

int main(int argc, char *argv[]) 
{
    if(argc != 2) {
        printf("Usage : ./a.out [set without spaces], eg. \"1234\" \n ");
        return 1;
    }
    subset(argv[1], 0);
    return 0;
}
