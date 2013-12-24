//sg
#include <stdio.h>
#include <string.h>

int isValid(char msb, char lsb) {
    char t[3];
    t[1] = lsb;
    t[0] = msb;
    t[2] = '\0';
    //printf("%s\n", t);
    int n = atoi(t);
    if(n <= 26) { 
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    unsigned long long int L[10100];
    int  i, l;
    char ip[10100];
    while(1) {
        scanf("%s", ip);
        if(ip[0] == '0') {
            break;
        }
        l = strlen(ip);
        L[0] = 1;
        if(ip[1] == '0') { 
            L[1] = 1;
            L[2] = 1;
            i = 3;

        } else if((isValid(ip[0], ip[1]))) {
            L[1] = 2;
            i = 2;
        } else {
            L[1] = 1;
            i = 2;
        }

        for(; i < l; i++) {
            if(ip[i] == '0') { 
               L[i + 1] = L[i] = L[i - 2];
               i++;
            } else if (!(isValid(ip[i - 1], ip[i]))) { 
                L[i] = L[i - 1];
            } else {
                L[i] = L[i - 1] + L[i - 2];
            }
        }
        printf("%lld\n", L[l - 1]);
    }
    return 0;
}
