//sg
#include<bits/stdc++.h>
using namespace std;
struct pt
{
    int x, y;
    pt(int x, int y):x(x), y(y){
    }
};


//rotate P about R by 90 deg
void rotate(pt &P, pt &R) {
    P.x = Rx + Ry - Py;
    P.y = -Rx + Ry + Px;
}

int main() {
    pt ini[4], home[4];
    int n;
    vector<pt> ini, home;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> xi >> yi >> ai >> bi;
            ini.push_back(pt(xi, yi));
            home.push_back(pt(ai, bi));
        }
        for(int i = 0; i < rotseq.length(); i++) {
            vector<int> seq = rotseq[i];
            for(int ptn = 0; ptn < 4; ptn++) {
                for(int rn = 0; rn < seq[ptn]; rn++) {
                    rotat

                

    return 0;
}


            

