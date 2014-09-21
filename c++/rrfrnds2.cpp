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
#define MAX 2009
typedef unsigned long long ui;
#define BITLEN 64
ui adj[MAX][500];

/*
 * Takes a BITLEN bit string and returns a number
 */
ui numBer(char *str) {
    ui res = 0;
    ui orWith = 0;
    for(int i = 0; i < BITLEN; i++) {
        if(str[i] == '1') {
            orWith = 1LL << (BITLEN - i - 1);
            res = (res | orWith);
        }
    }
    return res;
}

int amat[MAX][MAX];
bool haveCommonNbr(int i, int j, int numParts) {
    for(int k = 0; k <= numParts; k++) {
        if(adj[i][k] & adj[j][k]) {
            return true;
        }
    }
    return false;
}

void printStr(ui num) {
    for(int i = 0; i < BITLEN; i++) {
        printf("%c", (num & (1 << (BITLEN - i - 1))) ? '1' : '0');
    }
    printf("\n");
}

char adjStr[MAX][MAX];

int main() {
    int n;
    scanf("%d", &n);
    int numParts = ceil(float(n)  / BITLEN);
    //printf("numParts = %d\n", numParts);
    for(int i = 0; i < n; i++) {
        scanf("%s", adjStr[i]);
        for(int p = 0; p <= numParts; p++) {
            adj[i][p] = numBer(adjStr[i] + BITLEN * p);
        }
    }
    
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(adjStr[i][j] != '1' && haveCommonNbr(i, j, numParts)) {
                res += 2;
            }
        }
    }
    printf("%lld\n", res);
    return 0;
}
