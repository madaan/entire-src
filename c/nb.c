//sg
#include <stdio.h>
int digits(int x) {
    int res = 0;
    while(x) {
        res++;
        x = x / 10;
    }
    return res;
}
int hasSameDigits(int a, int b) {
int digs[10] = {0};
int i = 0;
if(digits(a) != digits(b)) {
    return 0;
}
while(a) {
    digs[a % 10] += 1;
    a /= 10;
}

while(b) {
    if(digs[b % 10] == 0) {
        return 0;
    }
    digs[b % 10]--;
    b = b / 10;
}
return 1;
}

int main()
{
    int N;
    scanf("%d", &N); //the number
    int dn = digits(N);
    int i;

    for(i = N + 1; digits(i) < dn + 1; i++) {
        if(hasSameDigits(i, N)) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Not possible\n");
    return 0;
}

