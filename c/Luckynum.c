//sg
#include<iostream>
#include<string.h>
using namespace std;
main()
{
 char N[100000]; 
 int l,lcount[10],count=0,cases;
 cin>>cases;
 for(int t=0;t<cases;t++)
 {
 cin>>N;
 l=strlen(N);
 for(int i=0;i<l;i++)
 {
   if((N[i]!='7')&&(N[i]!='4'))
   {
     count++;
   }
 }
 lcount[t]=count;
 count=0;
  }
  
 for(int t=0;t<cases;t++)
 {
   cout<<lcount[t]<<endl;
 }
}