//sg
#include<stdio.h>
#include<iostream>
using namespace std;
int getPali(unsigned int t)
{
    unsigned int res=0;
    while(t)
    {
        res*=10;
        res+=t%10;
        t/=10;
    }
    return res;
}
main()
{
    unsigned int n,t;
    int i=0,cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        while(i<1000)
        {
            t=getPali(n);
            if(n==t)
                break;
            else
                n=n+t;
            i++;
        }
        printf("%d %d\n",i,n);
        i=0;
    }
}
