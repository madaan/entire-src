//sg
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
main()
{
    char N[100000];
    register int i,count=0,cases;
    int lcount[10];
    scanf("%d",&cases);
    for(int t=0; t<cases; t++)
    {
        scanf("%s",N);

        for( i=0; N[i]!='\0'; i++)
        {
            if((	N[i]=='7')||(N[i]=='4'))
            {
                count++;
            }
        }
        lcount[t]=i-count;
        count=0;
    }

    for(int t=0; t<cases; t++)
    {
        cout<<lcount[t]<<endl;
    }
}