//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< vector < int > > MAT;
vector< MAT > sols;

void find_empty(int &r, int &c, MAT m) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(m[i][j] == 0) {
                r = i;
                c = j;
                return;
            }
        }
    }
    r = -1;
}

void print(MAT m) {
    sols.push_back(MAT(m));
}

bool valid(int arr[5]) {
    bool res = true;
    for(int i = 1; i <= 4; i++) {
        res = (res & arr[i] == 1);
    }
    return res;
}

bool isLegal(MAT m) {
    //check rows;
    int count[5];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            count[m[i][j]]++;
        }
        if(!valid(count)) {
            return false;
        }
        memset(count, 0, sizeof(count));
    }
        memset(count, 0, sizeof(count));

    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < 4; i++) {
            count[m[i][j]]++;
        }
        if(!valid(count)) {
            return false;
        }
        memset(count, 0, sizeof(count));
    }
        memset(count, 0, sizeof(count));

    for(int rb = 0; rb < 4; rb += 2) {
        for(int cb = 0; cb < 4; cb += 2) {
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    count[m[rb + i][cb + j]]++;
                }
            }   
            if(!valid(count)) {
                return false;
            }
        memset(count, 0, sizeof(count));
        }
    }
    return true;
}
 
 
void gen(MAT sud) {
    int r, c;
    find_empty(r, c, sud);
    //cout << "r : " << r << " m: " << m << "\n";
    if(r == -1) {
        if(isLegal(sud)) {
            print(sud);
        }
        return;
    }
    //check what has already been used in r and c
    int psnt[5];
    memset(psnt, 0, sizeof(psnt));
    for(int i = r, j = 0; j < 4; j++) {
        psnt[sud[i][j]] = 1;
    }
    for(int i = 0, j = c; i < 4; i++) {
        psnt[sud[i][j]] = 1;
    }
    
    for(int i = 1; i <= 4; i++) {
        if(psnt[i] == 0) {
            sud[r][c] = i;
            gen(sud);
        }
    }
}

void dump(MAT m) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    MAT x(4, vector<int>(4, 0));
    /*
    int arr[][4] = {
        {1,2,3,4},
        {3,4,1,2},
        {2,3,4,1},
        {4,1,2,3}};
    for(int i = 0; i < 4; i++) {
        x[i] = vector<int>(arr[i], arr[i] + 4);
    }
    */
    gen(x);
    cout << sols.size();
    return 0;
}
