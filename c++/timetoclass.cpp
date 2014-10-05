//sg
#include<bits/stdc++.h>
using namespace std;
class QuadraticLaw
{
    public:
    long long getTime(long long d) {
        long long result = (-1l + sqrtl(1l + 4l * d)) / 2l;
        return result;
    }
};

int main() {
    QuadraticLaw ql;
    cout << ql.getTime(1) << "\n";
    cout << ql.getTime(2) << "\n";
    cout << ql.getTime(5) << "\n";
    cout << ql.getTime(6) << "\n";
    cout << ql.getTime(7) << "\n";
    cout << ql.getTime(1482) << "\n";
    cout << ql.getTime(1482) << "\n";

    cout << ql.getTime(1000000000000000000) << "\n";
    cout << ql.getTime(31958809614643170) << "\n";
    cout << ql.getTime(999999998999999999) << "\n";
    cout << ql.getTime(1000000000000000000) << "\n";
    return 0;
}
