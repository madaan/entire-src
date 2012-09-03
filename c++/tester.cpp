//sg
#include<iostream>
using namespace std;
class Test
{
public:
Test()
{
cout<<"\nHello , an object is created";
}
void foo()
{
	cout<<"\nInside foo";
}
}obj1; //one way of creating the object
main()
{
	Test obj2;
	obj1.foo();
	obj2.foo();
}
