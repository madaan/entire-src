//sg
#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define answer 3.141593

int main(int argc, char **argv) {

        float a = (argc - 2)?: strtod(argv[1], 0);    
        printf("double = %lf ,float =  %f long long double = %lld", a-answer , a-answer , a-answer);

	return 0;
}
