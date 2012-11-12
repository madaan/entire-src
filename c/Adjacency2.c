//sg
#include<stdio.h>
#define MAX_NODE 10
int main()
{
	int a[MAX_NODE][MAX_NODE],c[MAX_NODE][MAX_NODE];
	int i,j,k,n;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	{
		printf("Edge from %d to %d (1 yes/0 no) ? : ",i+1,j+1);
		scanf("%d",&a[i][j]);
		a[j][i]=a[i][j];
	}
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		c[i][j]=0;
		printf("%d",a[i][j]);
	}
	printf("\n");
	}
	printf("\n");
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	for(k=0;k<n;k++)
	{
		c[i][j]+=a[i][k]*a[k][j];
	}
	
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		printf("%d",c[i][j]);
	}
	printf("\n");
	}
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	{
		if(c[i][j]==1&&(!a[i][j])&&(i!=j))
		{
			printf("\n%d - %d",i+1, j+1 );
			
		}
	}
	return 0;
}
