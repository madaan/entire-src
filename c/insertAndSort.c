//sg
#include<stdio.h>
void insert(int * a ,int *e,int l)
{
j=l-1;
l++;
if(j<0) 
{
a[0]=e;
return ;//first element
}
while(a[j]>e)
{
 j--;
 a[j+1]=a[j];
}
//found correct location
a[j+1]=e;
}
main()
{
int a[100],l=0,e;
while(e)
{
scanf("%d",&e);
insert(a,&l,e);

}

}
