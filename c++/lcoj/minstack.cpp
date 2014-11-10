//sg
#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> st;
    stack<int> min_stack;
    void push(int x) {
        if(st.empty()) {
            st.push(x);
            min_stack.push(x);
        } else {
            if(x <= min_stack.top()) {
                min_stack.push(x);
            }
            st.push(x);
        }

    }
    void pop() {
        if(st.empty()) {
            return;
        }
        int t = st.top();
        st.pop();
        if(min_stack.empty()) {
            return;
        }
        if(t == min_stack.top()) {
            min_stack.pop();
        }
    }
    int top() {
        if(st.empty()) {
            return -1;
        }
        return st.top();

    }
    int getMin() {
        if(st.empty()) {
            return -1;
        }
        return min_stack.top();
    }
};
int main() {
    MinStack ms;
    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647);
    cout << ms.top() << "\n";
    ms.pop();
    cout << ms.getMin() << "\n";
    ms.pop();
    ms.getMin();
    ms.pop();
    ms.push(2147483647);
    ms.top();
    ms.getMin();
    ms.push(-2147483648);
    ms.top();
    ms.getMin();
    ms.pop();
    ms.getMin();
    return 0;
}
