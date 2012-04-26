//sg
#include<iostream>
#define MAX 100000

using namespace std;
int num4[100001],num7[100001],pairs[100001],pairsEndingWithi[100001],prev;
int initNums()
{
int j,s=0,f=0,temp,mod;
  for(int i=1;i<=MAX;i++)
  {
    temp=i;
//     cout<<"processing "<<i<<endl;
    while(temp>0)
    {
      mod=temp%10;
      temp/=10;
      if(mod==4)
      {
	f++;
      }
      else if(mod==7)
      {
	s++;
      }
    }
    num4[i]=num4[i-1]+f;
    f=0;
    num7[i]=num7[i-1]+s;
    s=0;
    }
return 1;
}
unsigned int pairsEndingWith(int i)
{
  unsigned int pairs=0;
  int n4,n7;
  int test4,test7;
  test4=num4[i]-num4[i-1];
  test7=num7[i]-num7[i-1];
  if(((num4[i]-1)>num7[i])&&test4&&(!test7))
  {
    pairsEndingWithi[i]= pairsEndingWithi[i-1];
//     cout<<"assigning pairsEndingWith["<<i<<"]"<<pairsEndingWithi[i]<<"\n";   
    return pairsEndingWithi[i];
  }
   else if((num4[i]<(num7[i]-1))&&test7&&(!test4))
  {
    pairsEndingWithi[i]= pairsEndingWithi[i-1];
//     cout<<"assigning pairsEndingWith["<<i<<"]"<<pairsEndingWithi[i]<<"\n";
    return pairsEndingWithi[i];
  }
 else  if((!test4)&&(!test7))
  {
    pairsEndingWithi[i]= pairsEndingWithi[i-1]+1;
      return pairsEndingWithi[i];
  }/*	
  else if((!test7&&test4&&(prev!=4))
  {
    prev=4;
    pairsEndingWithi[i]= i-1-pairsEndingWithi[i-1];
      return pairsEndingWithi[i];
    
  }
  */	
//   cout<<"testing for "<<i<<endl;
  for(int l=1;l<=i;l++)
    {
      if((num4[i]-num4[l-1])==(num7[i]-num7[l-1]))
      pairs++;
    }
    pairsEndingWithi[i]=pairs;
  return pairs;
}
void initPairs()
{
 for(int i=1;i<=MAX;i++)
 {
   
   pairs[i]=pairs[i-1]+pairsEndingWith(i);
 }
}

main()
{
initNums();
initPairs();
int l,r,N,n4,n7,t=1;
unsigned int ans[MAX];
while(t){

cout<<"Enter t\n";
cin>>t;
for(int i=0;i<t;i++)
{
cin>>N;
 ans[i]=pairs[N];
}
for(int i=0;i<t;i++)
{
 cout<<ans[i]<<endl;
}
}
for(int i=0;i<100;i++)
{
  cout<<"\nNum 4 ["<<i<<"] = "<<num4[i]<<"\t";
  cout<<"Num 7 ["<<i<<"] = "<<num7[i]<<"    pairs [ "<<i<<"] = "<<pairs[i]<<endl;
  
}
}