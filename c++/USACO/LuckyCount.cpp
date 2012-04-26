//sg
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
void getCount(int j,int * cf,int * cs)
{
  //char num[100001];
//   sprintf(num,"%d",j);
  int mod;
//    cout<<"Testing "<<j<<endl;
   if(j==1)
   {
//     cout<<"J =1 ,count 7="<<*cs<<endl; 
   }
  while(j>0)
  {
    mod=j%10;
    j/=10;
    
  
    if(mod==7)
    {
     *cs=*cs+1; 
    }
    else if(mod==4)
    {
      *cf=*cf+1;
    }
  }
//   cout<<"Count 4 = "<<*cf<<" Count 7 = "<<*cs<<endl; 
}
main()
{
  int n,cf=0,cs=0,count4=0,count7=0,pairs=0;
  int count4table[100001],count7table[100001];
  for(int i=0;i<=100000;i++)
  {
    count4table[i]=count7table[i]=-1;
  }
  cin>>n;
  for(int r=n;r>=1;r--)
  { 
    for(int l=1;l<=r;l++)
    {
      for(int j=l;j<=r;j++)
      {
	if(count4table[j]<0)
	{
	  getCount(j,&cf,&cs);
	count4table[j]=cf;
	count7table[j]=cs;
	cs=cf=0;  
	}
	count4+=count4table[j];
	count7+=count7table[j];
      }
 	  cout<<"_________________________\n";
 	  cout<<"L= "<<l<<" R = "<<r<<endl;
 	  cout<<"count 4 ="<<count4<<" count 7 = "<<count7<<endl;
// 	  cout<<"\npairs="<<pairs;
      if(count4==count7)
      {
	pairs++;
	count4=count7=0;
      }
      else
      {
	count4=count7=0;
     break;
      }
      cout<<"\npairs = "<<pairs<<"\n";
    }
      
       
  }

 cout<<"ans= "<<pairs<<endl;
}