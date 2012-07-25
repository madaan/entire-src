//sg
#include<stdio.h>
#define NO_STUDENT 100000
main()
{
int n,i;
int studentGrade[NO_STUDENT];
int cookieCount=1,totalCount=0;
//printf("Enter the number of students\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&studentGrade[i]);
}
// i=0
totalCount+=cookieCount;
// i=1 to n-2
for(i=1;i<n-1;i++)
{
if((studentGrade[i]>studentGrade[i-1])||(studentGrade[i]>studentGrade[i+1]))
{
cookieCount++;
}
else
{
cookieCount=1;
}

totalCount+=cookieCount;
}
// i=n-1
if(studentGrade[i]<=studentGrade[i-1])
{
cookieCount=1;
}
else
{
cookieCount++;
}
totalCount+=cookieCount;
//printf("The total number of cookies required are : %d\n",totalCount);
printf("%d",totalCount);
}
