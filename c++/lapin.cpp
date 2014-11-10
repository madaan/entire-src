//sg
#include <cstdio>
#include <string.h>
char str[1000];
bool checkLapin(char *str) {
    int lhf[26], rhf[26];
    int l = strlen(str);
    int t;
    if(l % 2 == 0) {
        t = l/2;
    } else {
        t = l/2 + 1;
    }
    for(int i = 0; i < 26; i++) {
        lhf[i] = rhf[i] = 0;
    }
    for(int i = 0; i < l/2; i++) {
        lhf[str[i] - 97]++;
        rhf[str[i + t] - 97]++;
    }
    //check
    for(int i = 0; i < 26; i++) {
        if(lhf[i] != rhf[i]) {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", str);
        printf("%s\n", checkLapin(str)?"YES":"NO");
    }
    return 0;
}
