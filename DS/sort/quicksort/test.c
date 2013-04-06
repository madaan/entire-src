//sg
#include<stdio.h>
#define exchange(a,b) a=a^b;b=a^b;a=a^b;
main()
{
    int a[3];
    a[0] = 3;
    a[1] = 2;
    a[2] = 4;
    printf("a= %d b=%d", a[0], a[1]);
    exchange(a[0], a[1]);

    printf("a= %d b=%d", a[0], a[1]);
}
