//sg
#include <stdio.h>
#include <string.h>

char str1[2001], str2[2001];
int l1, l2;
int cache[2001][2001];

#define min(a, b) ((a < b) ? a : b)

int edist(int s1, int s2)
{
    if(cache[s1][s2] != -1) {
        return cache[s1][s2];
    }

    if(s1 == l1) {
        cache[s1][s2] = l2 - s2;
    } else if(s2 == l2) {
        cache[s1][s2] =  l1 - s1;
    } else if(str1[s1] == str2[s2]) {
        if(cache[s1 + 1][s2 + 1] == -1) {
           cache[s1 + 1][s2 + 1] = edist(s1 + 1, s2 + 1);
        }
        cache[s1][s2] = cache[s1 + 1][s2 + 1];
    } else {
        if(cache[s1][s2 + 1] == -1) {
            cache[s1][s2 + 1] = edist(s1, s2 + 1);
        }

        if(cache[s1 + 1][s2] == -1) {
            cache[s1 + 1][s2] = edist(s1 + 1, s2);
        }
        if(cache[s1 + 1][s2 + 1] == -1) {
            cache[s1 + 1][s2 + 1] = edist(s1 + 1, s2 + 1);
        }
    int add1 = cache[s1][s2 + 1] + 1;
    int add2 = cache[s1 + 1][s2] + 1;
    int replace = cache[s1 + 1][s2 + 1] + 1;
    cache[s1][s2] = min(add1, min(add2, replace));
    }
    return cache[s1][s2];
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s%s", str1, str2);
        //memset(cache, -1, sizeof(cache));
        l1 = strlen(str1);
        l2 = strlen(str2);
        for(int i = 0; i <= l1; i++) {
            for(int j = 0; j <= l2; j++) {
                cache[i][j] = -1;
            }
        }
        printf("%d\n", edist(0, 0));
    }
    return 0;
}
        
    
