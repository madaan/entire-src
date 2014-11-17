//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') {
            return *s == '\0';
        }
        if((*p != '*')) {
            if((*s == *p || (*p == '?' && *s)) && (isMatch(s + 1, p + 1))) {
                return true;
            }
            return false;
        }
        if(isMatch(s, p + 1)) {
            return true;
        }
        while(*s != '\0') {
            //cout << "s : " << s << "\n";
            if(isMatch(s + 1, p + 1)) {
                return true;
            }
            s++;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.isMatch(argv[1], argv[2]) << "\n";
    return 0;
}
