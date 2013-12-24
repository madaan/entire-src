//sg
#include <stdio.h>

int fof_id[11000], friends[1000];

int main()
{
    int num_friends, num_fof, tot_fof = 0, i, j, temp;
    scanf("%d", &num_friends);
    for(i = 0; i < num_friends; i++) {
        scanf("%d", &friends[i]);
        scanf("%d", &num_fof);
        for(j = 0; j < num_fof; j++) {
            scanf("%d", &temp);
            fof_id[temp] = 1;
        }
    }
    for(j = 0; j < 200; j++) { 
        fof_id[friends[j]] = 0;
    }
    for(j = 0; j < 10000; j++) {
        tot_fof = tot_fof + fof_id[j];
    }
    printf("%d\n", tot_fof);
    return 0;
}
