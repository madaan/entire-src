//sg
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
main()
{
int m,n,item2,item1,sack[100];
int nItemStack;
fstream of("TEST",ios::out);
srand ( time(NULL) );
for(int i=0;i<10;i++)
{
m=rand()%91+10;
n=rand()%801+200;
of<<"\n"<<m<<" "<<n<<"\n";
nItemStack=ceil((2*n)/(m-1)); //place the ceil
for(int i=0;i<m;i++) // populate
{
sack[i]=nItemStack;
}
//now each chef will pick up a tool
for(int j=0;j<n;j++)
{
item1=rand()%m+1;
sack[item1]--;
of<<item1<<" ";
}
for(int j=0;j<n;j++)
{
item2=rand()%m+1;
sack[item2]--;
of<<item2<<" ";
}
}
of.close();
}
