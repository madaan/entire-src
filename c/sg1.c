#include<stdio.h>
main()
{
char command = '1';
while(command!='0') {
    printf("Menu:\n");
    printf("1. First option\n");
    printf("2. Second option\n");
    printf("0. Exit\n");
    printf("Choose: 0,1,2?: ");
    command = getchar();
    while(getchar()!='\n');     
    switch(command) {
        case '0': break;
        case '1': printf("option 1");break;//functionCall1(); break; 
        case '2': printf("option 2");break;//functionCall2(); break;
    }
}
}
