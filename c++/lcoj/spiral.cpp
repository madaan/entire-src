//sg
#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int> > &mat) {
    int n = mat.size();
    vector<int> res;
    if(n == 0) {
        return res;
    }
    int m = mat[0].size();
    int r_l = -1, r_b = n, c_l = -1, c_r = m;
    int i = 0, j = 0;
    bool l, r, d, u;
    l = r = u = d = false;
    r = true;
    while(i > r_l && i < r_b && j < c_r && j > c_l) {
        //printf("i = %d, j = %d, %d \n", i, j, mat[i][j]);
        res.push_back(mat[i][j]);
        if(r) {
            j++;
            if(j == c_r) { //turn down
                r_l = i;
                j--;
                i++;
                r = false;
                d = true;
            }
        } else if(d) {
            i++;
            if(i == r_b) { //turn left
                c_r = j;
                i--;
                j--;
                d = false;
                l = true;
            }
        } else if(l) {
            j--;
            if(j == c_l) { //turn up
                r_b = i;
                i--;
                j++;
                l = false;
                u = true;
            }
        } else if(u) {
            i--;
            if(i == r_l) { //turn right
                c_l = j;
                i++;
                j++;
                u = false;
                r = true;
            }
        }
    }
    return res;
}
int main() {
    vector< vector<int> > a;
    spiralOrder(a);
    return 0;
}
