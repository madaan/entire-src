//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< vector < char > > CMAT;
typedef vector< vector < int > > IMAT;

void colorMats(CMAT x, int r, int c) {
    //counts of both the types
    IMAT rc(r, vector< int > (c, 0));
    IMAT bc(r, vector< int > (c, 0));
    

    for(int j = 0; j < c; j++) {
        for(int i = 0; i < r; i++) {
            if(x[i][j] == 'B') {
                bc[i][j] = bc[i - 1][j] + 1;
            }
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(x[i][j] == 'B') {
                bc[i][j] = bc[i - 1][j] + 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int r, c;
        cin >> r >> c;
        CMAT m(r, vector< char >(c, 0));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> m[i][j];
            }
        }



