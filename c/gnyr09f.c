//sg
#include <stdio.h>

int ADJ[200][200];

int adj(int n, int k)
{
    //printf("adj(%d, %d)\t", n, k);
    if(ADJ[n][k] != 0) {
        return ADJ[n][k];
    } 
    
    if(n < 0 || k < 0 || k >= n) { 
        return 0;
    }
   
    if(k == n - 1) { 
        return 1;
    }

    int res = 0;
    int nc = n, kc = k;
    if(ADJ[n - 1][k] == 0) { 
        ADJ[n-1][k] = adj(n - 1, k);
    }
    res = ADJ[n-1][k];
    n = n - 2;
    while(n >= 0 && k >= 0) {
            if(ADJ[n][k] == 0) {
                ADJ[n][k] = adj(n, k);
            }
            res = res + ADJ[n][k];
            k--;
            n--;

    }
    ADJ[nc][kc] = res;
    return ADJ[nc][kc];
}

int main()
{
    ADJ[0][0] = 1;
    ADJ[1][0] = 2;
    ADJ[2][0] = 3;
    ADJ[2][1] = 1;
    ADJ[3][0] = 5;
    ADJ[3][1] = 2;
    ADJ[3][2] = 1;
    ADJ[0][0] = 1;
    int t, i = 1, n, k;
    scanf("%d", &t);
    for(;i <= t; i++) {
        scanf("%d%d%d", &i, &n, &k);
        printf("%d %d\n", i, adj(n, k));
    }
    //printf("%d\n", adj(100, 90));
    return 0;
}
