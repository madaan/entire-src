//sg
#include<stdio.h>
#define MAX 100009
#define MAXL 500009
char ignored[MAXL];
int main() {
    int t, n, temp;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        bool valid = true;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            if(temp >= i) { //invalid
                valid = false;
                //break;
            }
        }
        /*
        if(!valid) { //need to eat the remainder
            scanf("%s", ignored);
        }
        */
        printf("%s\n", valid ? "YES" : "NO");
    }
    return 0;
}
