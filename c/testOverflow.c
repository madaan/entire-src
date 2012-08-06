//sg
#include<stdio.h>
main()
{
//a string of 5
char a[5];
scanf("%s",a);
// i enter a 4 length string , so scanf automatically appends a NULL at a[4]
//printf prints first 4 characters and bumps into a NULL at a[4] and then
//stops. everything is normal
printf("%s\n",a);
// if we tweak it - > 
a[4]='e'; //overwrite \0 NULL
//now there is no null character!
//printf has no way of telling when to stop, so it will keep printing
//characters till it bumps into a null by chance 
printf("%s\n",a);
}

