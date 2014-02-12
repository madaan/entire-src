#include <unistd.h> 
#include <stdio.h> 
#include <ctype.h> 

#include "kbhit.h" /* http://linux-sxs.org/programming/kbhit.html */

int main(){
  init_keyboard();
  char ch='x';
  int hit = 0;
  //takes input only if it is specified within 5 secs
  int DELAY_SECS = 5;
  while(DELAY_SECS--) {
    sleep(1);
    if(kbhit()) {
        hit = 1;
        break;
    }
  }
  if(hit == 1) {
      printf("Enter your input : ");
      scanf("%d", &hit);
      printf("You entered %d", hit);
  }
  //else return quitely
  close_keyboard();
  return 0;
}
