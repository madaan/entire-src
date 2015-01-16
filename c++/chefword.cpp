//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector< vector < double > > DMAT;
DMAT mul(DMAT A, DMAT B) {
    DMAT C(26, vector<double>(26, 0.0));
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            for(int k = 0; k < 26; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
DMAT powmat(DMAT a, int k) {
    if(k == 1) {
        return a;
    }
    if(k % 2 != 0) {
        return mul(a, powmat(a, k - 1));
    }
    DMAT half = powmat(a, k / 2);
    return mul(half, half);
}
double getTransProb(DMAT &charProb, string a, string b) {
    if(a.length() != b.length()) {
        return 0;
    }
    double res = 1;
    for(int i = 0, l = a.length(); i < l; i++) {
        res = res * charProb[a[i] - 97][b[i] - 97];
    }
    return res;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        cin >> n >> k;
        string chefs;
        cin >> chefs;
        DMAT probmat(26, vector<double>(26, 0));
        double entry;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                cin >> probmat[i][j];
            }
        }
        DMAT finalMat = powmat(probmat, k);
        /*
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                cout << finalMat[i][j] << " ";
            }
            cout << "\n";
        }
        */
        double res = 0;
        string finalStr;
        for(int i = 0; i < n; i++) {
            cin >> finalStr;
            res += getTransProb(finalMat, chefs, finalStr);
        }
        assert(res <= 1);
        cout << fixed << setprecision(15) << res << "\n";
    }
    return 0;
}
