//sg
#include "handlers.h"

int weirdMathFunc()
{
    return 1 / 0;
}

int main() 
{
    signal(SIGINT, ctrlc_handler);
    signal(SIGQUIT, ctrlbackspace_handler);
    signal(SIGFPE, divzero_handler);
    signal(SIGALRM, alarm_handler);
    int SIGTYPE, ALARMDUR;
    while(1) {
        printf("\nSelect a signal : \n 1. CTRL + C (SIGINT) \n 2. SIGKILL \n 3. Divide by zero (SIGFPE) \n 4. Alarm \n   > ");

        scanf("%d", &SIGTYPE);
        
        switch(SIGTYPE)
        {
            case 1:
                raise(SIGINT);
                break;
            
            case 2:
                raise(SIGKILL);
                break;
            
            case 3:
                weirdMathFunc();
                break;

            case 4:
                printf("\nEnter the alarm duration : ");
                scanf("%d", &ALARMDUR);
                alarm(ALARMDUR);
                break;

            default:
                printf("\nWrong choice!");
                break;
        }
    }
    return 0;
}
