//sg

#include<stdio.h>

void f(char **p)
{
char *t;
t = (p += sizeof(int))[-1];
printf("%s\n", t);
}
int main()
{
int r = 5,b=0,c=0;
char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" };
f(argv);
/*
//c=a++ + ++a + a++;
//printf("%d %d \n",b,c);
//printf("%d %d \n",b,c);
//a=5;switch(a){default:a = 4;case 6:a--;case 5:a = a+1;case 1:a = a-1;}printf("%d \n",a);
//*a gives you not an integer, but address of a 1d array on an integer
int a[][2] = {1, 2, 3, 4, 5, 6};
int (*ptr)[2] = a;
int * p2=*a;
printf("%d %d\n",*p2,*(p2+2));
printf("%d %d ", (*ptr)[1], (*ptr)[2]);
++ptr;
printf("%d %d\n", (*ptr)[1], (*ptr)[2]);
*/
char *s = "Opendays2012";
int i = 0;
while(*(s++))
i++;
printf("%d",i);
return 0;

}
