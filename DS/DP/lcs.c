//sg
#include<stdio.h>
#include<string.h>
char x[100],y[100],result[100];
int lcsLength,sptr;
int lcs(int m,int n)
{
if(m==-1||n==-1)
return 0;
if(x[m]==y[n])
{
printf("\n%c",x[m]);
result[sptr]=x[m];
sptr++;
lcsLength=lcs(m-1,n-1)+1;
}
else
{
int al,bl;
al=lcs(m-1,n);
bl=lcs(m,n-1);
lcsLength=((al>bl)?al:bl);
return lcsLength;
}

}
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
str[len]='\0';
}
main()
{
lcsLength=0;
printf("Enter the first string : ");
scanf("%s",x);
printf("Enter the second string : ");
scanf("%s",y);
puts("");
lcs(strlen(x)-1,strlen(y)-1);
strrev(result);
printf("%s\n",result);
printf("\nThe Length of LCS = %d\n",lcsLength);

}
