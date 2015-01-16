#include<iostream>
using namespace std;
double upow(double x, unsigned int n) {
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n == 2) return x * x;
    double res = upow(x, n / 2);
    if(n % 2 == 0) {
        return res * res;
    } else {
        return res * res * x;
    }
}
double pow(double x, int n) {
    if(n < 0) {
        return 1 / upow(x, -1 * n);
    } else {
        return upow(x, n);
    }
}
int main() {
    cout << pow(1.00000, -2147483648) << "\n";
    int a = -2147483648;
    cout << a << "\n";
    cout << -1 * a << "\n";
    return 0;
}
