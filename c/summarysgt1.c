//sg
#include<stdio.h>
main()
{
char * str1="AMITABH BACHCHAN", * str2="RAJNIKANTH";
int flag[26]={0};
while(*str1)
{
flag[(*str1)-65]=1;

str1++;  

  
}
puts("Common Alphabets are ->\n");
while(*str2)
{
  if(flag[(*str2)-65])
  {
   flag[(*str2)-65]=0;
    printf("%c \n",*str2);
     }
str2++;
 
  
}

}