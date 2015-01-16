//sg
#include<bits/stdc++.h>
using namespace std;
class LexRank
{
    string ip;
    string sorted;
    unordered_map<char, bool> used;
    int l;
    public:
    LexRank(string ip) : ip(ip) {
        l = ip.length();
        sorted = string(ip);
        sort(sorted.begin(), sorted.end());
    }

    int fact(int n) {
        int res = 1;
        for(int i = 2; i <= n; i++) res *= i;
        return res;
    }

    int beforeSortedUsed(char c) {
        int res = 0;
        for(int i = 0; sorted[i] < c; i++) if(!used[sorted[i]]) {
            res++;
        }
        return res;
    }

    int getRank() {
        int rank = 0;
        for(int i = 0; i < l; i++) {
            rank += (beforeSortedUsed(ip[i]) * fact(l - i - 1));
            used[ip[i]] = true;
        }
        return rank;
    }

};
int main() {
    LexRank lr("string");
    cout << lr.getRank() + 1 << "\n";
    return 0;
}
