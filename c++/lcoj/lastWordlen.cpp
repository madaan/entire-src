//sg
#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(const char *s) {
        string str(s);
        string tmp = "";
        int i = str.length() - 1;
        bool oneword = false;
        while(i >= 0 && s[i] != ' ') {
            tmp = s[i] + tmp;
            i--;
            oneword = true;
        }
        if(!oneword) {
            return 0;
        } else {
            return tmp.length();
        }
}

int main() {
    const char *s = "a";
    cout << lengthOfLastWord(s) << "\n";
    return 0;
}
