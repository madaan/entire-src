//sg
#include<bits/stdc++.h>
using namespace std;
class LK
{
    int N;
    string sol;
    set<char> used;

public:
    LK(int N, string sol) : N(N), sol(sol) {
    }

    void printElems() {
        string solved = "";
        for(int pos = 0; pos < N; pos++) {
            char corr = sol[pos];
            for(int i = 0; i < N; i++) {
                if(used.find(sol[i]) != used.end() || sol[i] == corr) continue;
                cout << sol[i] << solved;
            }
            cout << corr;
            used.insert(corr);
            solved += corr;
        }
    }
};

int main() {
    LK lk(4, string("1234"));
    lk.printElems();
    cout << "\n";
    return 0;
}
