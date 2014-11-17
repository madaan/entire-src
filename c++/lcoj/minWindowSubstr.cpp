//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string S, string T) {
        int l = 0;
        int r = 0;
        int inT[200] = {0};
        for(int i = 0, tl = T.length(); i < tl; i++) {
            inT[int(T[i])] = 1;
        }
        int gmax = 0;
        int maxi = 0;
        int count = 0;
        for(int i = 0, sl = S.length(); i < sl; i++) {
            if(inT(
    }
};
