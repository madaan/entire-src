//sg
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int num4(int l,int r)
{
    int temp;
    if(l==r)
    {
        r=0;
        while(l>0)
        {
            temp=l%10;
            l/=10;
            if(temp==4)
            {
                r++;
            }
        }
        return r;
    }
    else
        return num4(l,(l+r)/2)+num4((l+r)/2+1,r);
}
int num7(int l,int r)
{
    int temp;
    if(l==r)
    {
        r=0;
        while(l>0)
        {
            temp=l%10;
            l/=10;
            if(temp==7)
            {
                r++;
            }
        }
        return r;
    }
    else
        return num7(l,(l+r)/2)+num7((l+r)/2+1,r);
}
main()
{
    int n,cf=0,cs=0,count4=0,count7=0,pairs=0;
    int count4table[100001],count7table[100001];
    cin>>n;
    for(int r=n; r>=1; r--)
    {
        for(int l=1; l<=r; l++)
        {
            count4=num4(l,r);
            count7=num7(l,r);
//       cout<<"_________________________\n";
//  	  cout<<"L= "<<l<<" R = "<<r<<endl;
//  	  cout<<"count 4 ="<<count4<<" count 7 = "<<count7<<endl;
// 	  cout<<"\npairs="<<pairs;
            if(count4==count7)
            {
                pairs++;
                count4=count7=0;
            }
//        else
//        {
// 	count4=count7=0;
//       break;
//        }

        }


    }
    cout<<"ans= "<<pairs<<endl;
}