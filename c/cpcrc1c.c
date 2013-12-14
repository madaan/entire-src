//sg
#include <stdio.h>

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
int sumdigs(int n)
{
    int i, sum = 0;
    for(i = 0; i <= n; i++) { 
        //printf("%d = %d\n", i, digits(i));
        sum = sum + digits(i);
    }
    return sum;
}

int main()
{
    printf("%d\n", sumdigs(777) - sumdigs(99));
    return 0;
}

