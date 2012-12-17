//sg
//Poor O(n2) solution. 
#include<stdio.h>
#include<string.h>
int main()
{
	char flag[26];
	char input[200];
	int s,e;
	int i,j,prev=0;
	int ls,le;
	scanf("%s",input);
	int l=strlen(input);
	s=0;
	e=0;
	for(i=0;i<l;i++)
	{
		memset(flag,'0',sizeof(char)*26);
		s=i;
		e=s;
		j=i;
			while((flag[input[j]-'a']!='1')&&(j<l))
			{
				flag[input[j]-'a']='1';
				e++;
				j++;
			}
			if((e-s)>prev)
			{
				prev=e-s;
				ls=s;
				le=e-1;
			}
			if(j==l)
			break;
		}
		input[le+1]='\0';
	printf("%s",(input+ls));
	return 0;
}
