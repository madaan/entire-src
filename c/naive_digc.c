//sg
#include <stdio.h>
#include <stdlib.h>

int digits(int num)
{
    int sum = 0;
    while(num) {
        sum = sum + num % 10;
        num = num / 10;
    }
    return sum;
}
//
//returns sum of digits from 0 to n
long long sumdigs(int n)
{
    long long sum = 0, i;
    for(i = 0; i <= n; i++) { 
        //printf("%d = %d\n", i, digits(i));
        sum = sum + digits(i);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    printf("%lld\n", sumdigs(atoi(argv[2])) - sumdigs(atoi(argv[1]) - 1));
    return 0;
}
