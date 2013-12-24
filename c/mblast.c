//sg
#include <stdio.h>
#include <string.h>

#define abs(x) (x > 0 ? (x) : -(x))
#define min(x, y) (x > y ? y : x)
unsigned long long int cache[2005][2005];
char str1[2005], str2[2005];
int spaceDiff, l1, l2;

unsigned long long mindiff(int i, int j)
{
    //printf("mindiff(%d, %d)\n", i, j);
    
    if(cache[i][j] != 0) { 
        return cache[i][j];
    }
    if(i == l1 && j == l2) {
       return 0;
    }
    if(i == l1 && j < l2) {
       cache[i][j] =  spaceDiff * (l2 - j);
       return cache[i][j];
    } 
    if(j == l2 && i < l1) {
       cache[i][j] = spaceDiff * (l1 - i);
       return cache[i][j];
    } 
    int diff = abs(str1[i] - str2[j]);
    //printf("diff(%c, %c) = %d\n", str1[i], str2[j], diff);
    if(cache[i + 1][j + 1] == 0) { 
        cache[i + 1][j + 1] = mindiff(i + 1, j + 1);
    }
    if(cache[i + 1][j] == 0) {
        cache[i + 1][j] = mindiff(i + 1, j);
    }
    if(cache[i][j + 1] == 0) {
        cache[i][j + 1] = mindiff(i, j + 1);
    }

   cache[i][j] =  min(diff + cache[i + 1][j + 1], spaceDiff + min(cache[i + 1][j], cache[i][j + 1]));
    return cache[i][j];
}

int main()
{
    scanf("%s", str1);
    scanf("%s", str2);
    l1 = strlen(str1);
    l2 = strlen(str2);
    //printf("len(%s) = %d, len(%s) = %d\n", str1, l1, str2, l2);
    scanf("%d", &spaceDiff);
    printf("%lld\n", mindiff(0, 0));
    return 0;
}
