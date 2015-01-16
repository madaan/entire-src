//sg
#include<bits/stdc++.h>
using namespace std;
class Data
{
    int d;
    public:
    Data() {
        this->d = 0;
    }
    Data(int d) {
        this->d = d;
    }

    bool operator() (Data d1, Data d2) {
        return d1.d < d2.d;
    }

    int getD() {
        return d;
    }
};

int main() {
    priority_queue<Data, vector<Data>, Data> pq;
    for(int i = 0; i < 10; i++) {
        pq.push(Data(i));
    }
    while(!pq.empty()) {
        Data d = pq.top();
        cout << d.getD() << "\n";
        pq.pop();
    }
    return 0;
}
