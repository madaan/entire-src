//sg
//we can overload the subscript operator 
//and implement associative arrays
#include<iostream>
#include<stdlib.h>
#define LIMIT 100
using namespace std;

class safearray
{
int arr[LIMIT];
public:
int & operator [](int n)
{
if((n>=100)||(n<0))
{
cout<<"Error!";
}
return arr[47-n];
}
};
int main()
{
safearray sa;
sa['a']=11;
cout<<sa['a'];
}

