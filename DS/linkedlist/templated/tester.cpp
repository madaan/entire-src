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
LinkedList<int> ll;
for(int i=0;i<10;i++)
ll.addHead(i);
ll.display();
/*ll.addHead(1);
ll.addHead(2);
ll.addHead(3);
cout<<"Normal\n";
ll.display();
cout<<"Twisted\n";
ll.reverseList();
ll.display();

*/
return 0;
}
