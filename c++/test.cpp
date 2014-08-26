//sg
class A {
    int a;
    public :
    A(int ax) {
        a = ax;
    }
    int getA() const {
        return a;
    }
};

class B {
    int b;
    public:
    B(A const& aparam) {
        b = aparam.getA();
    }
};

int main() {
    A a(13);
    B b = A(13);
    return 0;
}
