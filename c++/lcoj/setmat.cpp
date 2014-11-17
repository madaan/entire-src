//sg
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    void setmoz(vector<vector<int> > &matrix, int m, int n) {
        bool found = false;
        for(int i = 0; i < m; i++) {
            found = false;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -2) {
                    found = true;
                    break;
                }
            }
            if(found) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] != -2) {
                        matrix[i][j] = 0;
                    }
                }
            }

        }
    }

    void solve(vector<vector<int> > &matrix) {
        setmoz(matrix, m, n);
        vector< vector< int > > tmat(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                tmat[j][i] = matrix[i][j];
            }
        }
        setmoz(tmat, n, m);
        /*
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                cout << setw(10) << tmat[j][i] << " ";
            }
            cout << "\n";
        }
        */
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = tmat[j][i];
            }
        }
    }
    void setZeroes(vector<vector<int> > &matrix) {
        m = matrix.size();
        n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][j] = -2;
                }
            }
        }
        solve(matrix);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -2) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

typedef vector< vector <int > > MAT;
int main() {
    int arr[][3] = {{2147483647,2,9},{2,6,7},{1,8,8},{5,0,1},{9,6,0}};
    MAT m;
    m.push_back(vector<int>(arr[0], arr[0] + 3));
    m.push_back(vector<int>(arr[1], arr[1] + 3));
    m.push_back(vector<int>(arr[2], arr[2] + 3));
    m.push_back(vector<int>(arr[3], arr[3] + 3));
    m.push_back(vector<int>(arr[4], arr[4] + 3));
    Solution s;
    s.setZeroes(m);
    int r = 5, c = 3;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
