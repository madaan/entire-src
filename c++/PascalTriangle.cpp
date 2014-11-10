//sg
#include<iostream>
using namespace std;
class PascalTriangle
{
public:
    int pt(int n,int r)
    {
        if((n==r)||(r==0))
            return 1;
        else
            return pt(n-1,r-1)+pt(n-1,r);
    }
};
int main()
{
    PascalTriangle pt1;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<=i; j++)
            cout<<pt1.pt(i,j)<<"  ";
        cout<<"\n";
    }
    return 1;
}
