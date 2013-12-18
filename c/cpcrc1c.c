//sg
#include <stdio.h>
#include <stdlib.h>
long long sum_power_10[] = {
    0, 
    45,
    900,
    13500,
    180000,
    2250000,
    27000000,
    315000000,
    3600000000,
    40500000000
    };

long long power10[] = { 
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000
    };


//returns the most significant digit and the power of 
//10 supporting it. For eg, for 2214, returns 2 and 3
//respectively.
void get_msd(int number, int *msd, int *power_msd) {
    int power = 0;
    while(number / 10) { 
        number = number / 10;
        power++;
    }
    *msd = number;
    *power_msd = power;
}

int chop_msd(int n) {
    char number[100];
    sprintf(number, "%d", n);
    if(number[1] == '\0') { //length 1?
        return 0;
    } else {
        return atoi(number + 1);
    }
}

long long int digc(int c)
{
    int msd, power_msd, i;
    long long  sum = 0;
    while(c) { //while the number is not zero
        get_msd(c, &msd, &power_msd);
        for(i = 0; i < msd; i++) {
            sum = sum + i * power10[power_msd] + sum_power_10[power_msd];
        }
        //last digit
        c = chop_msd(c);
        sum = sum + msd * (c + 1);
    }
    return sum;
}


int main(int argc, char *argv[])
{
    int a, b;
    while(1) {
        scanf("%d%d", &a, &b);
        if(a == -1) {
            break;
        }
        printf("%lld\n", digc(b) - digc(a - 1));
    } 
   return 0;
}

