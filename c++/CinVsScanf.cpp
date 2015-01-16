//sg
#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
void readScanf(int n)
{
    int i=0,a;
    cout<<"Scanf :\n ";
    for( i=0; i<n; i++)
        scanf("%d",&a);
}
void readCin(int n)
{
    int i=0,a;
    cout<<"Cin :\n ";
    for( i=0; i<n; i++)
        cin>>a;
}
int main(int argc,char * argv[])
{
    clock_t begin, end;
    double time_spent;
    begin = clock();
    freopen("tmp", "r", stdin);
    if(argc==2)
    {
        readScanf(100000);
    }
    else
        readCin(100000);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);
}
