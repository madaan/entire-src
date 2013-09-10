//sg
#include <stdio.h>
#include "gaussian.h"
int main()
{
    int ip;
    double u, sigma;
    printf("Enter u, sigma : ");

    scanf("%lf%lf", &u, &sigma);
    while(1) {
        printf("> ");
        scanf("%d", &ip);
        if(ip == 0) {
            break;
        }
        printf("Prob(%d) = %f\n",ip, prob(ip, sigma, u));
    }
    return 0;
}
