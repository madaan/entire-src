//sg
#include<iostream>
using namespace std;
class Shape {
public:
    virtual void area() = 0;
    virtual void version() {
        cout<<"\nVersion 1";
    }
};
class Rectangle: public Shape {
public :
    void area() {
        int a, b;
        cout<<"\nEnter sides :";
        cin>>a>>b;
        cout<<"\n Area => "<< a * b;
    }
    void version() {
        cout<<"\nThis is my version";
    }
};
class Circle:public Shape {
public:
    void area() {
        int r;
        cout<<"\nEnter radius :";
        cin>>r;
        cout<<"\n Area => "<< 3.1415 * r;
    }
};
int main() {
    Circle c;
    Rectangle r;
    Shape * s;
    s = &c;
    s -> area();
    s = &r;
    s->area();
    c.version();
    r.version();
    return 0;
}
