//sg
#include<stdio.h>
#include<string.h>
void main(void)
{
char str[100000];
int l,score=0,offset=1,toffset,i=0,cases=0;
scanf("%d",&cases);
while(cases--)
{
score=0,offset=1;
scanf("%s",str);
l=strlen(str);
score=l;
while(offset<l)
{
toffset=offset;
i=0;
while(((i+toffset)<l)&&(str[i]==str[i+toffset]))
//if first one fails , array index is never accessed, no chance of a seg fault
{score++;i++;
}
offset++;
}
printf("\n%d",score);
}
}
