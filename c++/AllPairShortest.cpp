//sg
#include<iostream>
using namespace std;
const int MAX=100;
class Graph
{
public:
    int ** A;
    int n;
    Graph(int n)
    {
        this->n=n;
        A=new int *[n];
        for(int i=0; i<n; i++)
        {
            A[i]=new int[n];
        }
    }
    void readAdj()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                {
                    A[i][j]=MAX;
                    continue;
                }
                cout<<" "<<i+1<<" to "<<j+1<<endl;
                cin>>A[i][j];
            }
        }
    }
    void readWeight()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                {
                    A[i][j]=MAX;
                    continue;
                }
                cout<<" "<<i+1<<" to "<<j+1<<endl;
                cin>>A[i][j];
                A[j][i]=A[i][j];
            }
        }
    }
    void print()
    {
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<A[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    void allPair()
    {
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(i==j)
                        continue;
                    if(A[i][j]>A[i][k]+A[k][j])
                    {
                        A[i][j]=A[i][k]+A[k][j];
                    }
                }
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    Graph g(n);
    g.readWeight();
    g.print();
    g.allPair();
    g.print();
}
