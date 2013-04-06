//sg
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertionsort(int * a,int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
j=i;
key=a[j];
while(j>0&&key<a[j-1])
{
a[j]=a[j-1];
j--;
}
a[j]=key;
}
}
int main(int argc,char * argv[])
{
int i;
printf("\n");
srand(time(NULL));
int * random, * seq, * userinput,*res;
int MAX=atoi(argv[2]);
if(!strcmp(argv[1],"rand"))
{
random=malloc(MAX*sizeof(int));
for( i=0;i<MAX;i++)
{
random[i]=rand()%10000000;
}
res=random;
insertionsort(random,MAX);
}
else if(!strcmp(argv[1],"seq"))
{
seq=malloc(MAX*sizeof(int));
for( i=0;i<MAX;i++)
{
seq[i]=i;
res=seq;
}
insertionsort(seq,MAX);
}
else
{
userinput=malloc(MAX*sizeof(int));
for(i=0;i<argc-3;i++)
{
userinput[i]=atoi(argv[i+3]);
}
res=userinput;
insertionsort(userinput,MAX);
}
for( i=0;i<MAX;i++)
printf("\n%d",res[i]);
printf("\n");
return 0;
}
