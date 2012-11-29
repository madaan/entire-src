///sg
/*/ * strtok example */
#include <stdio.h>
#include <string.h>
#include<time.h>

int main ()
{
float seconds;
int x;
for(int n=1;n<=1000;n++)
{
	x=0;
	clock_t start = clock();
for (int i=1; i<=n/2; i++)
  for(int j=i; j<=n-i;j++)
    for(int k=i;k<=j;k++)
      x++;
 
 clock_t end = clock();
 seconds = (float)(end - start) / CLOCKS_PER_SEC;
 printf("\n%f",seconds);
}
  return 0;
}
