//sg
#include<iostream>
using namespace std;
class WInt
{
int x;
public : 
WInt(int x)
{
this->x=x;
}
WInt()
{
x=0;
}
operator int() const
{
return x;
}
void outVal() const
{
cout<<" The value is "<<x<<"\n";
}
};
class WChar
{
char x;
public : 
WChar(char x)
{
this->x=x;
}
operator char() const
{
return x;
}
operator WInt() const
{
cout<<"Converting...\n";
return WInt(x-47);
}
};
int main()
{
WInt w(12),dummy;
WChar c('b');
int y;
char x;
dummy=static_cast<WInt>(c);
y=static_cast<int>(w);
x=static_cast<char>(c);
dummy.outVal();
cout<<y<<"\n"<<x<<"\n";
}
