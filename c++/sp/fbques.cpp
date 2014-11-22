//sg
#include<bits/stdc++.h>
using namespace std;
class BinNum
{
    int val;
    int numOnes;
    operator <(BinNum b) {
        if(numOnes < b.numOnes) {
            return true;
        } else if(val < b.val) {
            return true;
        }
        return false;
    }
};
int main() {
    return 0;
}


