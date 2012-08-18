//sg
#include<iostream>
#include "LinkedList.h"
/* template functions must be defined in the header files. This is 
 * because the compiler has to instantiate template functions at the
 * time of compilation. So the compiler must have direct access to the 
 * templates at the time of instantiation.
 */
 
using namespace std;
int main()
{
LinkedList<int> l1,l2;

for(int i=3;i<13;i+=3)
{
	l1.addHead(new int(i));
}
for(int i=4;i<13;i+=4)
{
	l2.addHead(new int(i));
}
l1.display();
l2.display();
l1.unionList(l2);
l1.intersect(l2);
return 0;
}
