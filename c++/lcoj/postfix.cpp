//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is_integer(const std::string & s) {
        int sl = s.length();
        int i = 0;
        if(s[0] == '-' && sl > 1) {
            i++;
        } else if(s[0] == '-') {
            return false;
        }
        for(; i < sl; i++) {
            if(!isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }
    int evalRPN(vector<string> &tokens) {
        int tl = tokens.size();
        stack<int> opstack;
        for(int i = 0; i < tl; i++) {
            string curr = tokens[i];
            if(is_integer(curr)) {
                cout << "pusing : " << stoi(curr) << "\n";
                opstack.push(stoi(curr));
            } else {
                assert(opstack.size() >= 2);
                int op1 = opstack.top();
                opstack.pop();
                int op2 = opstack.top();
                opstack.pop();
                if(curr == "*") {
                    opstack.push(op1 * op2);
                } else if(curr == "/") {
                    opstack.push(op2 / op1);
                } else if(curr == "+") {
                    opstack.push(op1 + op2);
                } else {
                    opstack.push(op2 - op1);
                }
            }
        }
        return opstack.top();
    }
};
int main() {
    vector<string> str;
    str.push_back("14");
    //str.push_back("-3");
    //str.push_back("-");
    Solution s;
    cout << s.evalRPN(str) << "\n";
    return 0;
}
