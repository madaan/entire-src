//sg
#include <stdio.h>
#include <string.h>
int main()
{
    int t, i, j;
    char *shorter, *longer;
    char name1[25009], name2[25009];
    scanf("%d", &t);
    while(t--) {
        scanf("%s%s", name1, name2);
        int l1 = strlen(name1);
        int l2 = strlen(name2);
        if(l1 == l2) { 
            if(!strcmp(name1, name2)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            continue;
        }

        if(l1 < l2) {
            shorter = name1;
            longer = name2;
        } else {
            shorter = name2;
            longer = name1;
        }
        i = j = 0;
        while(shorter[j] && longer[i]) {
            if((shorter[j] ^  longer[i]) == 0) {
                j++;
            }
            i++;
        }
        printf("%s", shorter[j] ? "NO\n" : "YES\n");
   }
return 0;
}
