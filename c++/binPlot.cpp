//sg
#include<stdio.h>
#define MAX_VAL 100
main()
{
int arr[MAX_VAL],n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
if(arr[i]==1)
{
printf(" _____");
}
else
{
printf("      ");
}
}
printf("\n");	
for(i=0;i<n;i++)
{

if(arr[i]==0)
{
printf(" _____");
}
else
{

printf("|     |");
}
}
printf("\n");
}	
