//sg
#include <stdio.h>
#include <string.h>
#define swap(a,b) a = a ^ b; b = a  ^ b; a = a ^ b;

void reverse(char *w, int si, int ei) {
    int i, j;
    for(i  = si; i  < si + ((ei - si + 1) / 2); i++) {
        swap(w[i], w[ei - (i - si)]);
    }
}

void rotate(char *w, int pos, int N) {
    reverse(w, 0, pos);
    reverse(w, pos + 1, N - 1);
    reverse(w, 0, N - 1);
}
void repeat(char *w, int n)
{
    int i;
    char o[5000];
    strcpy(o, w);
    for(i = 0; i < n - 1; i++) { 
        strcat(w, o);
    }
}

int main()
{
    int rep, ol, nl, i;
    char word[5000];
    while(1) {
        scanf("%s", word);
        if(!strcmp(word, ".")) {
            break;
        }
        scanf("%d", &rep);
        ol = strlen(word);
        repeat(word, rep);
        nl = ol * rep;
        for(i = 0; i < ol; i++) {
            printf("%s\n", word); 
            rotate(word, 0, nl);
        }
    }
    return 0;
}
