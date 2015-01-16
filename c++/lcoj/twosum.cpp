//sg
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<int> twoSum(vector<int> &numbers, int target) {
    map<int, vector<int>> indmap;
    for(int i = 0, l = numbers.size(); i < l; i++) {
        indmap[numbers[i]].push_back(i + 1);
    }
    sort(numbers.begin(), numbers.end());
    vector<int> res;
    for(int i = 0; i < numbers.size() - 1; i++) {
        vector<int>::iterator loc = lower_bound(numbers.begin() + i, numbers.end(), target - numbers[i]);
        cout << *loc << "\n";
        if(*loc == target - numbers[i]) {
            vector<int> inds = indmap[numbers[i]];
            int k = 0;
            while(inds[k] <= i) k++;
            res.push_back(inds[k]);
            inds = indmap[*loc];
            k = 0;
            while(inds[k] <= res[0]) k++;
            res.push_back(inds[k]);
            return res;
        }
    }
}
int main() {
    int arr[] = {5, 75, 25};
    vector<int> a(arr, arr + 3);
    vector<int> res = twoSum(a, 100);
    for(int r : res) {
        cout << r << " ";
    }
    cout << "\n";
    return 0;
}
