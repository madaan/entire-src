//sg
#include<stdio.h>
#include<iostream>
using namespace std;
struct tester
{
	char a[4];
	
	char b[4];
};
int main()
{
	tester t={"aaa","bbb"};
	//#1

	t.a[3]='a';
	t.b[3]='b';
	char * h=reinterpret_cast<char*>(&t);
	h=h+sizeof(tester);
	*h='w';
	h++;
	*h='2';
	cout<<t.a<<endl;
        return 0;
}
