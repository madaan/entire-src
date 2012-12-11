//sg
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
        int vet[1000], fre[51]={0};
        int i;

       
srandom(time(NULL));
        for(i=0;i<1000;i++){
       
                vet[i]=(random()%51);
        }

for(i=0;i<1000;i++){
printf("%d\n", vet[i]);
}

        for(i=0;i<1000;i++){
                        fre[vet[i]]=fre[vet[i]]+1;
        }

        for(i=0;i<51;i++){
                printf("The number %d  was generated %d times\n", i, fre[i]);
        }
        return 0;
}
