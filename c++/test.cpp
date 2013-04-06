//sg
#include <iostream>
using namespace std;
class AbsTest {
	public :
	virtual void voo()=0;
};
class Test:public AbsTest {
	int x;
	public :
	Test(int x) {
		this->x = x;
	}
	void foo(int args) const;
	void bar();
	void voo()
	{
		cout << "My Voo!";
	}
};
class CTest:public AbsTest {
	int x;
	public :
	CTest(int x) {
		this->x = x;
	}
	void foo(int args) const;
	void bar();
	virtual void voo()
	{
		cout << "Cy Voo!";
	}
};
void Test::foo(int args) const 
{
	args = args * 2;
}
void Test::bar() 
{
cout << "I do zilch";
}	
void CTest::foo(int args) const 
{
	args = args * 2;
}
void CTest::bar() 
{
cout << "I do zilch";
}	

int i = 40;
int main() {
              int i = 20;
           {  
              int i = 10;
              Test *  ast = new Test(13);
              CTest *  cst = new CTest(13);
              AbsTest * at= ast;
              at->voo();
              at = cst;
              at->voo();
              cout<< ::i<<"\n";  // prints 40
              cout<<i<<"\n";    // prints 10
              cout << *(&i + sizeof(int)); // how do i print variable i whose value is 20 
           }
   }
