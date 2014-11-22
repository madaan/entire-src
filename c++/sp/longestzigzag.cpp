//sg
#include<bits/stdc++.h>
using namespace std;
const int UP = 0;
const int DOWN = 1;
const int SAME  = 2;

bool opp(int prev, int next) {
    if((prev == UP && next == DOWN) || (prev == DOWN && next == UP)) {
        return true;
    } 
    return false;
}

int longzz(vector<int> &a) {
    int n = a.size();
    if(n < 3) {
        return n;
    }
    int len = 1;
    int ans = 0;
    int lw = 0, rw = 0;
    int prev = -1;
    bool isStart = true;
    //invariant, lw to rw always have a zz seq
    for(int pos = 1; pos < n; pos++) {
        int del;
        if(isStart) { //just want to initialize the array
            if(a[pos] > a[rw]) {
                prev = UP;
            } else if(a[pos] < a[rw]) {
                prev = DOWN;
            } else {
                prev = SAME;
            }
            rw++;
            len = 2;
            isStart = false;
            continue;
        }

        /*get the drift*/
        if(a[pos] > a[rw]) {
            del = UP;
        } else if(a[pos] < a[rw]) {
            del = DOWN;
        } else {
            del = SAME;
        }

        if(opp(prev, del)) {
            rw++;
            len++;
            ans = max(ans, len);
            prev = del;
        } else {
            len = 0;
            lw = rw = pos;
            isStart = true;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 4, 7, 2, 5};
    vector<int> a(arr, arr + 5);
    cout << longzz(a) << "\n";
    return 0;
}
