//sg
#define PARENT_DELAY 2
#define CHILD_DELAY 1
#include <stdio.h>
#include <unistd.h>
int main()
{
    int n, fdes[2];
    char BUFFER[100];

    if(pipe(fdes) < 0) {
        printf("Error creating the pipe\n");
        return -1;
    }
    pid_t childId = fork();
    if(childId == 0) {//child
        close(fdes[1]); //close child's write end
        while(1) {
            n = read(fdes[0], BUFFER, 100);
            write(STDOUT_FILENO, BUFFER, n);
            sleep(CHILD_DELAY);
        }
    } else {
        close(fdes[0]);
        int i = 1;
        char msg[100];
        while(i) {
            sprintf(msg, "P%d\n", i);
            write(fdes[1], msg , 4);
            i++;
            sleep(PARENT_DELAY);
        }
    }
return 0;
}
        
