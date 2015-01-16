//sg
#include<bits/stdc++.h>
using namespace std;


bool isTria(int a, int b, int c) {
    return (b + c >= a);
}

class trip
    {
    public:
    int a;
    int b;
    int c;
};
int getImpossibleCount(vector < int > lengths) {
    int l = lengths.size();
    sort(lengths.begin(), lengths.end());
    set<vector<int> > s;
    int res = 0;
   for(int i = 0; i < l; i++) {
       for(int j = i + 1; j < l; j++) {
           if(i == j) continue;
           vector<int>::iterator pos= upper_bound(lengths.begin() + j, lengths.end(), lengths[i] + lengths[j]);
           int idx = distance(lengths.begin(), pos);
           int ele = l - idx;
           res += ele;
       }
   }
   return res;
}


int main() {
    int arr[] = {4, 1, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(arr, arr + sz);
    cout << getImpossibleCount(vec) << "\n";
    return 0;
}
