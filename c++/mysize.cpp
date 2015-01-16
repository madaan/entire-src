//sg
#include <iostream>
using namespace std;
template <class T>
#define SO(X) mySizeof<X>()
int mySizeof()
{
    T * x;
    return (reinterpret_cast<int>(x + 1) - reinterpret_cast<int>(x));
}
class MyClass
{
    int x;
    float y;
    long long e;
    char name[100];
};
int main()
{
    std::cout << SO(int) << "\n" << SO(char) << "\n" << SO(MyClass);
    return 0;
}
