//sg
#include<iostream>
using namespace std;
int partition(int * a,int l,int r)
{
    int i,j,pivot,temp;
    pivot=a[r];
    i=l-1;
    for(int k=l; k<=r; k++)
    {
        if(a[k]<pivot)
        {
//   cout<<"Swapping "<<a[k] <<"and " <<a[i+1]<<"\n";
            temp=a[k];
            a[k]=a[i+1];
            a[i+1]=temp;
            i++;
        }
    }
//finally
    temp=a[r];
    a[r]=a[i+1];
    a[i+1]=temp;
    return i+1;
}
void quickSort(int * a,int l,int r)
{
    int p;
    if(l<r)
    {
        p=partition(a,l,r);
//   cout<<"\nP = "<<p;
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}
main()
{
    int n,a[100];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    quickSort(a,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<" "<<a[i];
    }
    cout<<endl;
}