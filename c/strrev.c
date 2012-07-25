//sg
#include<stdio.h>
#include<string.h>
void strrev(char * str)
{
int j;
char a,b;
int len=strlen(str);
for(j=0;j<len/2;j++)
{
str[j]=str[j]^str[len-j-1];
str[len-j-1]=str[j]^str[len-j-1];
str[j]=str[j]^str[len-j-1];
/*
asm(
"movb 3,%eax\n\t"
"movb 4,%ebx\n\t"
"pushl %eax\n\t"
"pushl %ebx\n\t"
"popl %eax\n\t"
"popl %ebx\n\t");
*/
}

}
main()
{
char a[100];
scanf("%s",a);
strrev(a);
printf("\n%s",a);
}
