//sg
#include <stdio.h>
#include <stdlib.h>
int fi(int n)
{
    int i = 2;
    double result = n;

    while(n != 1)
    {
        if(n % i == 0) {//found a divisor
            //printf("%d %d\n", result, i);
            //printf("%f %f\n", (1 - ((float)1 / i)), (1 - ((float)1 / i)) * result);
            result = result * (1 - ((float)1 / i));
        }
        while(n % i == 0) {
            n = n / i;
        }
        i++;
    }
    return result;
}

int main(int argc, char *argv[])
{
    int i;
    for(i = 1; i < argc; i++)
    printf("%d\n", fi(atoi(argv[i])));
    return 0;
}
