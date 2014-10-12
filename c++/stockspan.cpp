//sg
#include<bits/stdc++.h>
using namespace std;
vector< int > span(vector< int > arr) {
    vector< int > res(arr.size());
    stack<int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(st.empty() || arr[i] >= arr[st.top()]) {
            st.push(i);
        } else {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                int curr = st.top();
                st.pop();
                res[curr] = curr - i - 1;
            }
            st.push(i);
        }
    }
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        res[curr] = curr;
    }

    return res;
}

int main() {
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    vector< int > vec(arr, arr + 7);
    vector< int > leftg = span(vec);
    reverse(vec.begin(), vec.end());
    vector< int > rightg = span(vec);
    reverse(vec.begin(), vec.end());
    reverse(rightg.begin(), rightg.end());
    vector<int> total(rightg.size());
    int res = 0;
    for(int i = 0; i < rightg.size(); i++) {
        total[i] = leftg[i] + rightg[i] + 1;
        res = max(res, arr[i] * total[i]);
    }
    cout << res << "\n";
    return 0;
}
