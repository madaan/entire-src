//sg
#include<iostream>
using namespace std;
int main()
{
void * p1;
int * p2, * p3;

p2 = new int;
p1 = p2;
p3 = (int *) p1;
delete p2;
//delete p3;
delete (int *) p1;
}

