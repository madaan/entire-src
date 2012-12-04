#include <iostream>
#include <string>

char a[100];
using namespace std;
class X
{
	public:
	static int x;
	static char xu;
	static char xua[100];
};
int X::x;
char X::xu;
char X::xua[100];
int main() {
    string password;
cout<<X::x;
cout<<endl<<X::xu;
cout<<endl<<X::xua;
    
 return(0);

}
