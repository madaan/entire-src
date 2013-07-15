//sg
#include<stdio.h>
int main()
{
int a[10];
int i=0;
int res=0,n;
printf("Enter the number of elements, followed by the elements...");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",(a+i));
for(i=0;i<n;i++)
{
	res=res^a[i];
}
printf("\nXOR OF ALL BUT THE DUPLICATE NUMBER : %d",res);
for(i=0;i<n;i++)
{
	res=res^a[i];
}
printf("\nDuplicate element is : %d",res);
return 0;
}
