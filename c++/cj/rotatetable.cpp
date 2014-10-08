//sg
#include<bits/stdc++.h>
using namespace std;

void rev(string &str) {
    int l = str.length();
    for(int i = 0; i < l / 2; i++) {
        str[i] ^= str[l - i - 1];
        str[l - i - 1] ^= str[i];
        str[i] ^= str[l - i - 1];
    }
}

void rotate(vector< string > &mat) {
    int r = mat.size();
    int c = mat[0].size();
    for(int i = 0; i < r; i++) {
        for(int j = i + 1; j < c; j++) {
            mat[i][j] ^= mat[j][i];
            mat[j][i] ^= mat[i][j];
            mat[i][j] ^= mat[j][i];
        }
    }
    for(int i = 0; i < r; i++) {
        rev(mat[i]);
    }

}

bool searchRow(vector < string > &mat, char col, int k) {
    int r = mat.size();
    int c = r;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int sl = 0;
            while(j < c && mat[i][j] == col) {
                sl++;
                j++;
            }
            if(sl >= k) {
                return true;
            }
        }
    }
    return false;
}

bool searchCol(vector < string > &mat, char col, int k) {
    int r = mat.size();
    int c = r;
    for(int j = 0; j < c; j++) {
        for(int i = 0; i < r; i++) {
            int sl = 0;
            while(i < r && mat[i][j] == col) {
                sl++;
                i++;
            }
            if(sl >= k) {
                return true;
            }
        }
    }
    return false;
}


bool searchDiagR(int i, int j, int n, char ele, vector < string > &mat, int k) {
    int sl = 0;
    while(i < n && j < n && mat[i][j] == ele) {
        i++;j++;
        sl++;
    }
    return sl >= k;
}

bool searchDiagL(int i, int j, int n, char ele, vector < string > &mat, int k) {
    int sl = 0;
    while(i < n && j >= 0 && mat[i][j] == ele) {
        i++;j--;
        sl++;
    }
    return sl >= k;
}

bool searchDiag(vector < string > &mat, char ele, int k) {
    int n = mat[0].length();
    bool res = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
        res = res | searchDiagL(i, j, n,  ele, mat, k);
        res = res | searchDiagR(i, j, n, ele, mat, k);
        res = res | searchDiagL(j, i, n, ele, mat, k);
        res = res | searchDiagR(j, i, n, ele, mat, k);
    }
    }
    return res;
}

void gravity(vector< string > &mat) {
    int r = mat.size();
    int c = mat[0].size();
    for(int i = 0; i < c; i++) {
        string temp;
        for(int j = 0; j < r; j++) {
            if(mat[j][i] != '.') {
                temp += mat[j][i];
            }
        }
        int tl = temp.length();
        for(int dots = 0; dots < r - tl;dots++) {
            mat[dots][i] = '.';
        }
        for(int p = 0; p < tl; p++) {
            mat[p + r - tl][i] = temp[p];
        }


    }
}


int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        int n, k;
        cin >> n >> k;
        vector < string > mat;
        string temp;
        for(int i = 1; i <= n; i++) {
            cin >> temp;
            mat.push_back(temp);
        }
        
        rotate(mat);
        gravity(mat);
        
        /*
        for(int i = 0; i < n; i++) {
            cout << "\n" << mat[i];
        }
        */
        //start searching
        //red
        bool isRed = searchRow(mat, 'R', k) || searchCol(mat, 'R', k) || searchDiag(mat, 'R', k);
        bool isBlue = searchRow(mat, 'B', k) || searchCol(mat, 'B', k) || searchDiag(mat, 'B', k);
        if(isRed && isBlue) {
            cout << "Both\n";
        } else if(isBlue) {
            cout << "Blue\n";
        } else if(isRed) {
            cout << "Red\n";
        } else {
            cout << "Neither\n";
        }
    }
    return 0;
}
