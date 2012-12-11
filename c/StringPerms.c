//sg
#include<stdio.h>
#include<string.h>
void swap(char * str,int a,int b)
{
	char t;
	t=str[b];
	str[b]=str[a];
	str[a]=t;
}
void permStrings(char * str,int s,int e)
{
	if(s>e)
	return;
if(s==e)
{
	printf("%s\n",str);
	return;
}	
int i=0;
for(i=s;i<=e;i++)
{
	swap(str,s,i);
	permStrings(str,s+1,e);
	swap(str,s,i);
}
}
int main(int argc,char * argv[])
{
	
	permStrings(argv[1],0,strlen(argv[1])-1);
	return 0;
}
