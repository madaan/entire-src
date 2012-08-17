//sg
#include<iostream>
#include<stdlib.h>
using namespace std;
class A
{
	public:
	~A()
	{
		cout<<" I am called!\n";
	}
};
main()th
{
	A * a=new A();
	cout<<"Let me free aptr :";
	free(a);
	cout<<"\nNow let's delete it!\n";
	a=(A *)malloc(sizeof(A));
	delete(a);
}
