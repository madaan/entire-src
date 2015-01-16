//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sl, pl;
    bool res(string str, int sp, string pat, int pp) {
        bool str_emp = (sp >= sl);
        bool pat_emp = (pp >= pl);
        if(str_emp ^ pat_emp) {
            return false;
        }
        if(str_emp && pat_emp) {
            return true;
        }
        if(pat[pp + 1] != '*') {
            if(str[sp] == pat[pp] || pat[pp] == '.') {
                return res(str, sp + 1, pat, pp + 1);
            }
            return false;
        }
        if(res(str, sp, pat, pp + 2)) {
            return true;
        }
        for(int i = sp; i < sl; i++) {
            if(str[i] == pat[pp] || pat[pp] == '.') {
                if(res(str, i + 1, pat, pp + 2)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isMatch2(const char *s, const char *p) {
        string s1(s);
        sl = s1.length();
        string s2(p);
        pl = s2.length();
        return res(s1, 0, s2, 0);
    }

    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') {
            return *s == '\0';
        }
        if(*(p + 1) != '*') {
            if(*s == *p || *p == '.') {
                return isMatch(s + 1, p + 1);
            }
            return false;
        }
        while(*s  == *p || (*p == '.')) {
            if(isMatch(s, p + 2)) {
                return true;
            }
            s++;
        }
        return isMatch(s, p + 2);
    }
};

int main(int argc, char *arg[]) {
    //const char *s = "aaaaaaaaaaaaaaaaaaaaaaa";
    //const char *p = "a*";
    //const char *s = "baccbbcbcacacbbc";
    //const char *p = "c*.*b*c*ba*b*b*.a*";
    //const char *s = "cbcacbaaabcbabbcaa";
    //const char *p = "b*aa*a*.*b*..*c*bc*";

    Solution ob;
    cout << ob.isMatch(arg[1], arg[2]) << "\n";
    return 0;
}
