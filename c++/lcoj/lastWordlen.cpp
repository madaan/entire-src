//sg
#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(const char *s) {
    string str(s);
    str.erase(str.find_last_not_of(" \n\r\t")+1);
    str.erase(0, str.find_first_not_of(" \n\r\t"));
    reverse(str.begin(), str.end());
    stringstream ss(str);
    string temp;
    ss >> temp;
    return temp.length();
}
int main() {
    const char *s = " aa madd   ";
    cout << lengthOfLastWord(s) << "\n";
    return 0;
}
