//sg
#include<iostream>
using namespace std;
main()
{
int * a=new int[10];
for(int i=0;i<10;i++)
{a[i]=i;}

delete a;
a=new int[5];
for(int i=0;i<5;i++)
{
a[i]=i;
}

for(int i=0;i<5;i++)
{
cout<<a[i]<<"\n";
}
delete a;
}

