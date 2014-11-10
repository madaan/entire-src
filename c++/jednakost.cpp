//sg
#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#define MAXA 1100
#define MAXB 5100
using namespace std;
int cache[MAXB][MAXA];
int l;
string ip;
int getMinOps() {
    cache[0][getInt(ip, l - 1, l - 1)] = 0;
    for(int offset = 1; offset < l; offset++) {
        for(int i = 0; i  < 4; i++) {
            if(l - offset - 1 + i == l) {

                int temp = getInt(ip, l - offset - 1, l - offset - 1 + i);
                int getInt(string ip, int l, int r) {
                    return atoi(ip.substr(l, r - l + 1).c_str());
                }
                int main() {
                    string s = "1002434";
                    string subs = s.substr(2, 2);
                    cout << getInt(s, 1, 3) << endl;
                    return 0;
                }

