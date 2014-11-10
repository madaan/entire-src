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
char b[110][110];
bool iso(int i, int j) {
    return (b[i][j] == 'o');
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", b[i]);
    }
    bool hasEven = true;
    int no;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            hasEven = true;
            no = 0;
            if(i > 0 && iso(i - 1, j)) { //up
                no++;
            }
            if(j > 0 && iso(i, j - 1)) { //left
                no++;
            }
            if(i < n - 1 && iso(i + 1, j)) { //down
                no++;
            }
            if(j < n - 1 && iso(i, j + 1)) { //right
                no++;
            }
            if(no % 2 != 0) {
                hasEven = false;
                break;
            }
        }
        if(!hasEven) {
            break;
        }

    }
    if(hasEven) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}


