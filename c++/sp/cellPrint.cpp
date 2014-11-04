//sg
#include<bits/stdc++.h>
using namespace std;
vector< string > chars;
int k;
void print(int pos, string ip, string str) {
    //cout << pos << "\n";
    if(pos == k) {
        cout << str << "\n";
        return;
    }
    int dig = ip[pos] - 48;
    if(dig == 0 || dig == 1) {
        print(pos + 1, ip, str);
    }
    for(int i = 0, l = chars[dig].length(); i < l; i++) {
        str[pos] = chars[dig][i];
        //cout << str << "\n";
        print(pos + 1, ip, str);
    }
}

int main() {
    k = 3;
    char const * const char_strs[]= {"",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};
    for(int i = 0; i < 10; i++) {
        chars.push_back(string(char_strs[i]));
        //cout << "chars[" << i << "] = " << chars[i] << "\n";
    }
    string res = "   ";
    print(0, "234", res); 
    return 0;
}
