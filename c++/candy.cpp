//sg
#include <stdio.h>
int main() {
    int numPacks;
    int packets[11000];
    while(1) {
        scanf("%d", &numPacks);
        if(numPacks == -1) {
            break;
        }
        int sumPacks = 0;
        for(int i = 0; i < numPacks; i++) {
            scanf("%d", &packets[i]);
            sumPacks = sumPacks + packets[i];
        }
        if(sumPacks % numPacks != 0) {
            printf("-1\n");
            continue;
        }
        int quantPerPack = sumPacks / numPacks;
        int moved = 0;
        //need to process
        for(int i = 0; i < numPacks; i++) {
            if(packets[i] < quantPerPack) {
                moved = moved + (quantPerPack - packets[i]);
            }
        }
        printf("%d\n", moved);
    }
    return 0;
}
