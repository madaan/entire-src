//sg


#include<iostream>
using namespace std;
int main()
{
const int i = 10 ;
  int * p = const_cast<int *>(&i);
  cout<<"\ni="<<i<<"  &i"<<&i;;
  cout<<"\n*p="<<*p<<"  p="<<p;
  *p=4;
  cout<<"\ni= "<<i<<"&i"<<&i;;
  cout<<"\n*p="<<*p<<"  p="<<p;
   	
return 0;
}
