//sg
#include<stdio.h>
#include<string.h>
#define ANAGRAMS 1
#define NOT_ANAGRAMS 0
int readline(char * buff,int length)
{
char ch;
fgets(buff,length,stdin);
if(buff[strlen(buff)-1]!='\n') 
{
//pull out characters
while((ch=getchar())!='\n'&&ch!=EOF)
;
return 0;
}
buff[strlen(buff)-1]='\0';
}
void removeSpaces(char * buff)
{
int read=0,copy=0;
while(buff[read])
{
if(buff[read]==' ')
{
while(buff[read]==' ')
{
read++;
}
}
else
{
buff[copy++]=buff[read++];
}
}
buff[copy]='\0';
}
int checkAnagram(char * a,char * b)
{
int flag[26],i=0;
for(i=0;i<26;i++)
{
flag[i]=0;
}
i=0;
while(a[i])
{
flag[a[i]-97]++;
i++;
}
i=0;
while(b[i])
{

if(flag[b[i]-97]==0)
{
return NOT_ANAGRAMS;
}
else
{
flag[b[i]-97]--;
}
i++;
}
return ANAGRAMS;
}
int main()
{
char str1[100],str2[100];
readline(str1,100);
readline(str2,100);
removeSpaces(str1);
removeSpaces(str2);
if(checkAnagram(str1,str2)==ANAGRAMS)
{
printf("Anagrams!\n");
}
else
{
printf("Not Anagrams!\n");
}
}
