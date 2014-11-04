//sg
#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
        virtual void print() {
            cout << "A\n";
        }
    ~A() {
        cout << "Going out\n";
    }
};

class B:public A
{
    public:
        virtual void print() {
            cout << "B\n";
        }
};

class C:public B
{
    public:
        virtual void print() {
            cout << "C\n";
        }
};

int main() {
    A *a = new A();
    ((B *)a)->print();
    return 0;
}
