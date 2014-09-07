//sg
#include<cstdio>
#include<cstring>
int  n;
long long res;
char ip[30];
int a[30];
void f(int pos, int leftSum) {
    //printf("f(%d, %d)\n", pos, leftSum);
    if(pos == n) {
        res++;
        return;
    }
    int sum = 0;
    //f(pos + 1, leftSum + a[pos]);
    for(int i = pos; i < n; i++) {
        sum += a[i];
        if(leftSum <= sum) { //can create a new group at i
            //printf("here pos = %d ls=%d\n", pos, leftSum);
            f(i + 1, sum);
        }

    }
}

int main() {
    int i = 1;
    while(true) {

        scanf("%s", ip);
        if(!strcmp("bye", ip)) {
            return 0;
        }
        for(n = 0; ip[n]; n++) {
            a[n] = ip[n] - '0';
        }
        res = 0;
        f(0, 0);
        printf("%d. %lld\n", i++, res);
    }
    return 0;
}



