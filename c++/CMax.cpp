//sg
#include<stdio.h>
using namespace std;
int V[100],C[100];
int A[100];
int res[10001];
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
int main()
{
    int i,n,max=0,maxIn=0,cases;
    scanf("%d",&cases);
    for(int t=0; t<cases; t++)
    {
        scanf("%d",&n);
        for( i=0; i<n; i++) //read the array
        {
            scanf("%d",&A[i]);
            res[A[i]]++;
        }
        quickSort(A,0,n-1);
//find the max
        for(int j=0; j<n; j++) //read the array
        {
            i=A[j];
            if(res[i]>max)  //only possible for nonzero res[i]
            {
                max=res[i];
                maxIn=i;
            }
            res[i]=0;
        }
        V[t]=maxIn;
        C[t]=max;
        max=0;
        maxIn=0;
    }
    for(int t=0; t<cases; t++)
    {
        printf("%d %d\n",V[t],C[t]);
    }
    return 0;
}