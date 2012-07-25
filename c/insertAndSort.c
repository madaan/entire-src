//sg
#include<stdio.h>
#define N 100000
#define debug
void insert(int * a ,int e,int *l)
{
int j=*l-1;
*l=*l+1;
if(j<0) 
{
a[0]=e;
return ;//first element
}
while((a[j]>e)&&(j>=0))
{
 a[j+1]=a[j];
 j--;
}
//found correct location
a[j+1]=e;
}
int delete(int * a ,int e,int *l)
{
int leftLocation=binsearch(a,e,*l);
if(*l==0)
{
return ;
}
if(leftLocation==*l-1)//last element?
{
*l=*l-1;
return *l;
}
if(leftLocation==-1)
{
printf("\nWrong!");
return -1;
}
//now loop to reach the last element in case of duplicate element
while((leftLocation<(*l-1))&&(a[leftLocation]==a[leftLocation+1]))
{
leftLocation++;
}
leftLocation--;//adjust
//now start overwriting
while(leftLocation<*l)
{
a[leftLocation]=a[leftLocation+1];
leftLocation++;
}
*l=*l-1;
return *l;
#ifdef debug
printf("Found at %d\n",leftLocation);
#endif
}
int binsearch(int *a,int e,int len)
{
int l,r,mid;
l=0;
r=len-1;
while(l<=r)
{
mid=(l+r)/2;
if(a[mid]==e)
{
return mid;
}
else if(a[mid]<e)
{
l=mid+1;
}
else
{
r=mid-1;
}
}
return (-1);
}
float getMedian(int * a,int l)
{
if(l==0)
{
return 0.0f;
}
if(l%2==0)//even
{
l--;
return ((float)(a[l/2]+a[l/2+1])/2);
}
else
{
l--;
return (float)a[l/2];
}
}
#ifdef debug
void print(int * a,int l)
{
int i=0;
for(i=0;i<l;i++)
{
printf("%d ",a[i]);
}
puts("");
}
#endif
main()
{
int l=0,e,lines,i,arg,found;
unsigned int a[N];
char move,str[200];
scanf("%d",&lines);#endif
//scanf("%c%d",&move,&arg);
fgets(str,200,stdin);
sscanf(str,"%c%*c%d",&move,&arg);
#ifdef debug
printf("\nMOVE : %c ARG : %d",move,arg);
#endif
switch(move)
{
case 'a':
#ifdef debug
printf("\nAdding element number %d\n",l+1);
#endif
insert(a,arg,&l);
printf("\n%g",getMedian(a,l));
break;
case 'r' :
if(l==0) //array empty
{
printf("\nWrong!");
continue;
}
#ifdef debug
printf("\nDeleting element number %d\n",l+1);
#endif

found=delete(a,arg,&l);
if(l==0) //array empty after deletion?
{
printf("\nWrong!");
continue;
}
if(found!=-1) //if found is -1, the result WRONG has been printed already
{
printf("\n%g",getMedian(a,l));
}
break;
}
}
}
