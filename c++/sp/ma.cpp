//sg
#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int winSize;
    cin >> winSize;
    if(winSize < 0) {
        return 0;
    }
    assert(winSize > 0);
    double tmp;
    deque<double> dq;
    int read = 0;
    double avg = 0;
    double sum = 0;
    const int PRECISION = 3;
    string line;
    cin.clear();
    cin.ignore();
    while(std::getline(std::cin, line)) {
        tmp = atof(line.c_str());
        dq.push_back(tmp);
        read++;
        sum += tmp;
        if(read == winSize) {
            avg = sum / winSize;
            break;
        }
    }
    if(read < winSize) {
        return 0;
    }
    //now roll the average
    cout << fixed << setprecision(PRECISION) << avg << "\n";
    while(std::getline(std::cin, line)) {
        tmp = atof(line.c_str());
        double slide_elem = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
        sum = sum - slide_elem + tmp;
        avg = (sum) / static_cast<double>(winSize);
        //printf("%.3f\n", avg);
        cout << fixed << setprecision(PRECISION) << avg << "\n";
    }
    return 0;
}
