//sg
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
main()
{
char * s1,* s2;
s1=(char *)malloc(sizeof(char)*26);
s2=(char *)malloc(sizeof(char)*26);

int flags[26],anagram=1,cases,i=1;
scanf("%d",&cases);
for( i=0;i<26;i++)
flags[i]=0;
while(cases--)
{
anagram=1;
scanf("%s%s",s1,s2);
if(strlen(s1)!=strlen(s2))
{
anagram=0;
goto done;
}

while(*s1)
{
flags[(*s1)-97]++;
s1++;
}
while(*s2)
{
flags[(*s2)-97]--;
s2++;
}

for( i=0;i<26;i++)
{if(flags[i]!=0)
{
flags[i]=0;
anagram=0;
}
}
done:
if(anagram)
puts("YES\n");
else
puts("NO\n");

}
}

