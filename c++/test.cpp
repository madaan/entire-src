//sg
#include <iostream>
using namespace std;

int i = 40;
int main() {
              int i = 20;
           {  
              int i = 10;
              cout<< ::i<<"\n";  // prints 40
              cout<<i<<"\n";    // prints 10
              cout << *(&i + sizeof(int)); // how do i print variable i whose value is 20 
           }
   }
