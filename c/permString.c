#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * charSet;
int * taken;
void permStringWithRep(char * str,int n)
{
int i=0;
if(n==0)
{
printf("%s\n",str);
return;
}
for(i=0;i<n;i++)
{
if(!taken[i])
{
taken[i]=1;
str[n-1]=charSet[i];
permStringWithRep(str,n-1);
taken[i]=0;
}
}
}
main(int argc,char * argv[])
{
char str[100];
int * takenLocal,l,i;
if(argc!=2)
{
printf("Usage permStr [word]\n");
exit(0);
}
charSet=argv[1];
l=strlen(charSet);
takenLocal=(int *)calloc(l,sizeof(int));
for(i=0;i<l;i++)
{
printf("%d\n",takenLocal[i]);
}
taken=takenLocal;
permStringWithRep(str,l);
}

