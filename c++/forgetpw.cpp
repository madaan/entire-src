//sg
#include<stdio.h>
#include<string.h>

char ip[1000009];

void trim(char *ptr) {
    int len = strlen(ptr);
    int decimalLoc = 0;
    bool foundDec = false;
    char *trimmed = new char[len + 1];
    for(int i = 0; i < len; i++) {
        if(ptr[i] == '.') {
            foundDec = true;
            decimalLoc = i;
            break;
        }
    }
    int leftSearchBoundary = 0;
    int leftOk = 0; //index from where left is okay
    //need to trim from left
    if(ptr[0] == '0') {
        if(foundDec) {
            leftSearchBoundary = decimalLoc;
        } else {
            leftSearchBoundary = len;
        }
        int i = 0;
        for(i = 0; i < leftSearchBoundary && ptr[i] == '0'; i++) {
        }
        leftOk = i;
    }
    if(leftOk == len) { //all zeroes?
        printf("0\n");
        return;
    }

    int rightOk = len - 1; //index from where the right is okay
    if(foundDec && ptr[len - 1] == '0') { //need to trim from right
        int i = 0;
        for(i = len - 1; i > decimalLoc && ptr[i] == '0'; i--) {
        }
        rightOk = i;
    }

    if(!foundDec) { //no decimal
        ptr[rightOk + 1] = '\0';
        printf("%s\n", ptr + leftOk);
    } else {
        if(leftOk == decimalLoc && rightOk == leftOk) {
           printf("0\n");
        } else if(rightOk == decimalLoc) {
            ptr[rightOk] = '\0';
            printf("%s\n", ptr + leftOk);
        }
        else {
            ptr[rightOk + 1] = '\0';
            printf("%s\n", ptr + leftOk);
        }
    }
    return;
}

int main() {
    char rules[250];
    int t, N;
    char l, r;
    scanf("%d", &t);
    while(t--) {
        //clear the rules
        for(int i = 33; i <= 126; i++) {
            rules[i] = ' ';
        }
        scanf("%d", &N);
        //printf("N : %d\n", N);
        while(N > 0) {
            getchar(); //eat the newline from the previous read
            scanf(" %c %c", &l, &r);
            rules[l] = r;
            //printf("%c -> %c\n", l, r);
            N--;
        }
        scanf("%s", ip);
        //printf("ip : %s\n", ip);
        int i = 0;
        while(ip[i]) {
            if(rules[ip[i]] != ' ') { //need to map
                ip[i] = rules[ip[i]];
            }
            i++;
        }
        int len = i;
        trim(ip);
    }
    return 0;
}
