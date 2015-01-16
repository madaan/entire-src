//sg
#include<bits/stdc++.h>
using namespace std;
class A {
    int a;
public:
    void func() {
        cout << "A func\n";
    }
};
class B : public A {
    int b;
public:
    virtual void func() {
        cout << "B func\n";
    }
};
class C : public B {
    int b;
public:
    void func() {
        cout << "C func\n";
    }
};
int main() {
    A *bs = new C();
    bs->func();
    C c;
    c.func();
    return 0;
}
