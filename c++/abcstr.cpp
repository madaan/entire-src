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
int cum[1000010][3];
#define alleq(i) (cum[i][0] == cum[i][1] && cum[i][1] == cum[i][2] && cum[i][0] == cum[i][2])
bool eq(int l, int r) {
    int a, b, c;
    /* if(l == 0) {
         a = cum[r][0];
         b = cum[r][1];
         c = cum[r][2];
     } else {*/
    a = cum[r][0] - cum[l - 1][0];
    b = cum[r][1] - cum[l - 1][1];
    c = cum[r][2] - cum[l - 1][2];
    //}
    //printf("l = %d, r = %d \n a = %d, b = %d, c = %d\n", l, r, a, b, c);
    return (a == b) && (b == c) && (a == c);
}
int main()
{
    char s[1000010];
    long long int match = 0;
    scanf("%s", s);
    int index = 0, i = 0;
    for(i = 1; s[i - 1]; i++) {
        index = s[i - 1] - 65;
        cum[i][0] = cum[i - 1][0];
        cum[i][1] = cum[i - 1][1];
        cum[i][2] = cum[i - 1][2];
        cum[i][index] = cum[i - 1][index] + 1; // let 0 be 0
    }
    int len = i;
    for(int l = 1; l < len; l++) {
        for(int r = l + 2; r < len; r++) {
            if(eq(l, r)) {
                //printf("%d, %d\n", l, r);
                match++;
                r += 2;
            }
        }
    }
    printf("%lld\n", match);
    return 0;
}
