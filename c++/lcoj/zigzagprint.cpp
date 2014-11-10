//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        vector< string > res(nRows, string(""));
        bool up = false;
        int rowNum = 0;
        for(int i = 0, l = s.length(); i < l; i++) {
            ///out << s[i] << " -> " << rowNum << "\n";
            res[rowNum] = res[rowNum] + s[i];
            if(up) {
                rowNum--;
                if(rowNum == -1) {
                    rowNum = nRows == 1 ? 0 : 1;
                    up = false;
                }
            } else {
                rowNum++;
                if(rowNum == nRows) {
                    rowNum = nRows == 1 ? 0 : nRows - 2;
                    up = true;
                }
            }
        }
        string finalStr = "";
        for(int i = 0; i < nRows; i++) {
            finalStr = finalStr + res[i];
        }
        return finalStr;
    }
};
int main() {
    Solution s;
    cout << s.convert("ABC", 2) << "\n";
    return 0;
}
