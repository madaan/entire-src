//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator ii;

int main(int argc, char *argv[]) {
    int k; //window size
    try {
        ifstream file_in(argv[1]);
        file_in >> k;
        if(k <= 0) {
            return 0;
        }
        deque<double> k_queue;
        int read = 0;
        vector<double> arr;
        double tmp;
        double avg = 0; //the moving average
        double sum = 0;
        //read the first k elements first
        while(file_in >> tmp) {
            k_queue.push_back(tmp);
            sum += tmp;
            read++;
            if(read == k) { //have read a window
                avg = sum / k;
                break;
            }
        }
        cout << fixed << setprecision(3) << avg << "\n";
        while(file_in >> tmp) {
            double slide_over = k_queue.front();
            k_queue.pop_front();
            //cout << slide_over << "\n";
            sum = sum - slide_over + tmp;
            avg = sum / k;
            k_queue.push_back(tmp);
            cout << avg << "\n";
        }
        file_in.close();
    }
    catch(int e) {
        cout << "There was a trouble, program has crashed\n";
    }
    return 0;
}
