    //sg
    #include<iostream>
    #include<stdio.h>
    #define TRUE 1
    #define FALSE 0
    using namespace std;
    void convert(int * b)
    {
		gets(b);
		int i=0;
		while(a[i])
		{
			if(a[i]!=' ')
			{
				b[i+1]=a[i]-48;
			}
				
		}
	}
    int isAmbiguous(int * a,int n)
    {
    int i;
    for(i=1;i<=n;i++)
    {
    if(a[a[i]]!=i)
    {
	 printf("not ambiguous\n");
    return FALSE;
    }
    }
    printf("ambiguous\n");
    return TRUE;
    }
    int main()
    {
		char starr[200009];
    int arr[100002],//the array
    n,//number of elements
    i;//simple iterator
 
    while(scanf("%d",&n)&&(n!=0))
    {
    cin.getline(starr,'\n');
    convert(starr,arr);
    for(i=0;i<=n;i++)
    printf("\n%d",arr[i]);
    isAmbiguous(arr,n);
    }
    return 0;
    }
