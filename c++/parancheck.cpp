//sg
#include <stdio.h>
#include <string.h>
#include <stack>
#include <stdlib.h>
bool paranChecker(char *str)
{
    std::stack<char> st;
    if(str == NULL) {
        return false;
    }
    if(strlen(str) == 0) {
        return true;
    }
    int i = 0;
    while(str[i]) {
        if(str[i] == ')') {
            if(st.empty()) {
                return false;
            } else {
                st.pop();
            }
        } else {
            st.push('(');
        }
        i++;
    }
    return st.empty();
}
int n;
void listParan(char *str, int l) {
    //printf("len = %d str = %s\n", l, str);
    if(l == n && paranChecker(str)) {
        printf("%s\n", str);
        return;
    }
    int no = 0, nc = 0;
    for(int i = 0; i < l; i++) {
        if(str[i] == '(') {
            no++;
        } else {
            nc++;
        }
    }
    if(no == nc && !paranChecker(str)) {
        return;
    }
    if((l > n / 2) &&(no == 0 || nc == 0)) {
        return;
    }
    if(l < n) { //currently a valid paran
        if(no < n / 2) {
            char *str1 = new char[l + 2];
            strcpy(str1, str);
            listParan(strcat(str1, "("), l + 1);
        }
        if(nc < n / 2) {
            char *str2 = new char[l + 2];
            strcpy(str2, str);
            listParan(strcat(str2, ")"), l + 1);
        }
    }
}
int main(int c, char *v[])
{
    n = atoi(v[1]);
    char *str = new char[1];
    str[0] = '\0';
    listParan(str, 0);
    return 0;
}
