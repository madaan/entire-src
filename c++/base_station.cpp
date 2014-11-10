//sg
#include<bits/stdc++.h>
using namespace std;
class Frame
{
    int header[1];
public:
    Frame(int a) {
        header[0] = a;
    }
    virtual void extractHeader() {
        cout << "Frame\n";
        cout << header[0] << "\n";
    }
};
class SuperFrame:public Frame
{
    int header[2];
public:
    SuperFrame(int a, int b):Frame(a) {
        header[0] = a;
        header[1] = b;
    }
    void extractHeader() {
        cout << "SuperFrame\n";
        cout << header[0] << " " << header[1] << "\n";
    }
};
class AnotherFrame:public Frame
{
    int header[3];
public:
    AnotherFrame(int a, int b, int c):Frame(a) {
        header[0] = a;
        header[1] = b;
        header[2] = b;
    }
    void extractHeader() {
        cout << "AnotherFrame\n";
        cout << header[0] * header[1] << "\n";
    }
};
class Subscriber
{
public:
    void process(Frame *f) {
        f->extractHeader();
    }
};
int main() {
    Frame *f = new Frame(1);
    Subscriber s;
    s.process(f);
    f = new SuperFrame(1, 2);
    f = new AnotherFrame(1, 2, 3);
    s.process(f);
    return 0;
}
