#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack_pointer = 0;
char *stack[30]; //MAX NUMBER OF VALUES IN STACK IS 30

int main(int argc, char** argv) {

    char command_line[256];

    while(stack_pointer < 5) {  //Just store 5 inputs
        stack[stack_pointer] = malloc(sizeof(char) * 256);
        printf("repl> ");
        scanf("%s",command_line);
        strcpy(stack[stack_pointer], command_line);  
        stack_pointer++;
    }   

    int i = 0;
    for(i = 0; i<5; i++) {
        printf("stack[%d] =  %s\n", i, stack[i]);
    }
}
