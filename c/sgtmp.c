//sg
#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
main()
{
char ch;
while(ch!='o')
{
if(kbhit())
{

ch=getchar();
if(ch==8)
printf("\b");
else

printf("*");

}
}
}
