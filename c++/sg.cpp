//sg
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;
void disp5() {
    cout << "2 * 4 = 8\n5 * 3 = 15\n15 + 8 = 23\n23 + 1 = 24\n";
}
void disp4() {
    cout << "4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n";
}
void disp6() {
    cout << "6 * 5 = 30\n30 - 4 = 26\n26 - 3 = 23\n2 - 1 = 1\n23 + 1 = 24\n";
}
void disp7() {
    cout << "7 * 5 = 35\n6 * 4 = 24\n35 - 24 = 11\n11 * 2 = 22\n3 - 1 = 2\n22 + 2 = 24\n";
}
int main() {
    int n;
    cin >> n;
    if(n < 4) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int type;
    int arr[] = {4, 5, 6, 7};

    for(int i = 0; i < 4; i++) {
        if((n - arr[i]) % 4 == 0) {
            type = arr[i];
            break;
        }
    }
    for(int j = n, pos = 0; j > type; j-=2, pos++) {
        if(pos % 2 == 0) {
            printf("%d - %d = %d\n", j, j - 1, 1);
        } else {
            printf("%d - %d = %d\n", j - 1, j, -1);
        }
    }
    switch(type) {
    case 5:
        disp5();
        break;
    case 6:
        disp6();
        break;
    case 7:
        disp7();
        break;
    case 4:
        disp4();
        break;
    }
    int nones = (n - type) / 2;
    //cout << "type " << type << "nones = " << nones << "\n";
    for(int i = 0; i < nones / 2; i++) {
        cout << "1 + -1 = 0\n";
    }
    for(int i = 0; i < nones / 2; i++) {
        cout << "24 + 0 = 24\n";
    }
    return 0;
}


