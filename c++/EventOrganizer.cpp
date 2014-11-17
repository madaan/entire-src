//sg
#include<iostream>
#include<stdio.h>
#define debugd
using namespace std;
class Event
{
public:
    int st;
    int et;
    long long int profit;
    bool taken;
    Event(int st,int et,int profit)
    {
        this->st=st;
        this->et=et;
        this->profit=profit;
        this->taken=false;
    }
    Event()
    {
    }
};
int partition(Event e[],int k,int r)
{
    int i,j,x;
    x=e[k].et;
    Event temp;
    i=k;
    //i+1 to j are all > pivot
    for(j=k+1; j<=r; j++)
    {
        if(e[j].et<x)
        {
            i++;
            temp=e[i];
            e[i]=e[j];
            e[j]=temp;
        }
    }
    temp=e[k];
    e[k]=e[i];
    e[i]=temp;
    return i;
}
void quickSortByEnd(Event e[],int l,int r)
{
    if(l<r)
    {
        int q=partition(e,l,r);
        quickSortByEnd(e,l,q-1);
        quickSortByEnd(e,q+1,r);
    }
}
int binSearch(Event e[],int si,int N)
{
    int l=1,r=N,mid;
    mid=(l+r)/2;
    while(l<=r)
    {
        //cout<<"Searching : l= "<<l<<" r= "<<r<<"\n";
        if(e[mid].et==si)
        {
            break;
        }
        if(l==r)
        {
            break;
        }
        if(e[mid].et>si)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        mid=(l+r)/2;
    }
    while(e[mid].et<=si)
    {
        mid++;
    }
    return mid-1;
}
/* H(i) : Number of activities that finish
 * before ith activity starts*/
void calculateH(int H[],Event e[],int N)
{
    for(int i=1; i<=N; i++)
    {
        H[i]=binSearch(e,e[i].st,N);
    }
}
long long int organize(Event e[],int H[],int N)
{
    long long int * profit=new long long int[2001];
    long long int aP=0;
    e[0].taken=true;
    profit[0]=0;
    for(int i=1; i<=N; i++)
    {
        aP=e[i].profit+profit[H[i]];
        profit[i]=((profit[i-1]>aP)?profit[i-1]:aP);
    }
    return profit[N];
}
int main()
{
    int n,i=0,s,e,c,T;
    Event earr[2001];
    int H[2001];
    scanf("%d",&T);
    while(T--)
    {
        i=1;
        scanf("%d",&n);
        while(i<=n)
        {
            scanf("%d%d%d",&s,&e,&c);
            earr[i].st=s;
            earr[i].et=e;
            earr[i].profit=c;
            i++;
        }
        quickSortByEnd(earr,1,n);
        calculateH(H,earr,n);
        printf("%lld\n",organize(earr,H,n));
    }
    return 0;
}
