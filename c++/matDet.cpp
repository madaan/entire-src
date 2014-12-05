//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< vector <int > > MAT;



//returns the matrix after deleting the rth row and cth column
MAT smallerMat(MAT m, int n, int r, int c) {
    MAT res;
    for(int i = 0; i < n; i++) {
        if(i == r) continue;
        vector<int> row;
        for(int j = 0; j < n; j++) {
            if(j == c) continue;
            row.push_back(m[i][j]);
        }
        assert(row.size() == n - 1);
        res.push_back(row);
    }
    return res;
}

int det(MAT m, int n) {
    if(n == 1) {
        return m[0][0];
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        MAT smat = smallerMat(m, n, 0, i);
        res = res + (det(smat, n - 1) * m[0][i]) * (pow(-1, i));
    }
    return res;
}

int main() {
    int arr[][6] = {{1, 2, 3, 1, 2, 3}, 
                    {4, 6, 2, 1, 2, 3}, 
                    {112, 23, 4, 1, 2, 3},
                    {1, 2, 3, 233432, 2, 3}, 
                    {1, 1, 2, 1, 2, 3}, 
                    {1, 23, 42324, 1, 2, 3}
    };
    int n = 6;
    MAT m;
    for(int i = 0; i < n; i++) {
        m.push_back(vector<int>(arr[i], arr[i] + n));
    }
    cout << det(m, n) << "\n";
    return 0;
}
