//sg
#include<bits/stdc++.h>
int mat[100][100];
int n, m;
void printMatSpiral() {
    int r_l = -1, r_b = n, c_l = -1, c_r = m;
    int i = 0, j = 0;
    bool l, r, d, u;
    l = r = u = d = false;
    r = true;
    while(i > r_l && i < r_b && j < c_r && j > c_l) {
        printf("i = %d, j = %d, %d \n", i, j, mat[i][j]);
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
}
int main() {
    int e = 1;
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) 
            mat[i][j] = e++;
            //mat[i][j] = (i + 1) * (j + 1);
    n = m = 3;
    printMatSpiral();
    return 0;
}
