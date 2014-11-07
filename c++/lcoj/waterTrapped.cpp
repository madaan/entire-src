//sg
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int trap(int A[], int n) {
    if(n == 0) {
        return 0;
    }
    vector<int> nextBig(n);
    stack<int> st;
    st.push(0);
    int i = 1;
    while(i < n) {
        if(A[st.top()] > A[i]) {
            st.push(i);
        } else {
            while(!st.empty() && A[st.top()] <= A[i]) {
                int te = st.top();
                if(A[te] <= A[i]) {
                    nextBig[te] = i;
                    st.pop();
                }
            }
            st.push(i);
        }
        i++;
    }
    while(!st.empty()) {
        nextBig[st.top()] = -1;
        st.pop();
    }
    int res = 0;
    /*
    for(int i = 0; i < n; i++) {
        cout << nextBig[i] << "\n";
    }
    */
    for(int i = 0; i < n - 1;) {
        if(nextBig[i] != -1) { 
            int nxt = nextBig[i]; //water will fill between i and nxt
            int j = i + 1;
            while(j < nxt) {
                res += (A[i] - A[j]);
                j++;
            }
            i = nxt;
        } else if(A[i + 1] < A[i] && nextBig[i + 1] != -1) {
            //water will fill again, but with different height
            int nxt = nextBig[i + 1];
            while(nextBig[nxt] != -1) {
                nxt = nextBig[nxt];
            }
            int ht = A[nxt];
            int j = i + 1;
            while(j < nxt) {
                res += (ht - A[j]);
                j++;
            }
            i = nxt;
        } else {
            i++;
        }
    }
    return res;
}

int main() {
    //int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    //int arr[] = {0,7,1,4,6};
    //int arr[] = {4, 2, 3};
    cout << trap(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
    return 0;
}
