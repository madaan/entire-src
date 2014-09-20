//sg
#include<bits/stdc++.h>
int main() {
    char str[100009];
    int result = 0;
    int mod = 1000000007;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", str + 1);
        int i = 1;
        result = 1;
        while(str[i]) {
            if(i % 2 != 0) {
                result = (str[i] == 'l') ? (result * 2) : (result * 2 + 2);
                result = result % mod;
            } else {
                result = (str[i] == 'l') ? (result * 2 - 1) : (result * 2 + 1);
                result = result % mod;
            }
            i++;
        }
        printf("%d\n", result);
    }
    return 0;
}
