//sg
#include <stdio.h>

int array1[5] = {2, 4, 6, 8, 10};
int array[5] = {2, 4, 6, 8, 10};
int *pointer;


int main()
{
        pointer = array;
        printf("%p:\t%d\n", pointer, *pointer);
        return 0;
}
