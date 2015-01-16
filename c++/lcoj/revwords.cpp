//sg
#include<bits/stdc++.h>
using namespace std;
void reverseWords(string &s) {
    stringstream ss(s);
    stack<string> st;
    string temp;
    while(getline(ss, temp, ' ')) {
        if(temp != " " && temp != "\n" && temp.length() > 0) {
            cout << temp << "\n";
            st.push(temp);
        }
    }
    string res = "";
    while(!st.empty()) {
        res += st.top() + " ";
        st.pop();
    }
    s = string(res);
    s.erase(s.find_last_not_of(" \n\r\t")+1);
    s.erase(0, s.find_first_not_of(" \n\r\t"));
}
int main() {
    string s("   a   b ");
    reverseWords(s);
    cout << s << "\n";
    return 0;
}
