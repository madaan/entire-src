//sg
#include<bits/stdc++.h>
using namespace std;
bool isOpen(char c) {
    return c == '(' || c == '[' || c == '{';
}
bool isClosing(char c) {
    return c == ')' || c == ']' || c == '}';
}
bool matches(char o, char c) {
    if(o == '(') {
        return c == ')';
    } else if(o == '[') {
        return c == ']';
    } else {
        return c == '}';
    }
}
bool isValid(string s) {
    stack<char> st;
    int i = 0;
    st.push(s[0]);
    i++;
    while(s[i]) {
        if(isOpen(s[i])) {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            }
            int tb = st.top();
            st.pop();
            if(isOpen(tb)) {
                if(!matches(tb, s[i])) {
                    return false;
                }
            } else {
                return false;
            }
        }
        i++;
    }
    return st.empty();
}
int main() {
    cout << isValid("[])") << "\n";
    return 0;
}
