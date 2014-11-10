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
string s;
int n, p;
char limit;
char alpha[] = "abcdefghijklmnopqrstuvwxyz";
char nxt(char p, char pp) {
    for(char c = 'a'; c <= limit; c++) {
        if(c != p && c != pp) {
            //printf("nxt(%c, %c) = %c\n", p, pp, c);
            return c;
        }
    }
    return '1'; //something is really bad
}
char nxt(char p) {
    for(char c = 'a'; c <= limit; c++) {
        if(c != p) {
            //printf("nxt(%c) = %c\n", p, c);
            return c;
        }
    }
    return '1'; //something is really bad
}
bool isOk(int pos, char c) {
    if(pos == 0) {
        return true;
    }
    if(pos == 1) {
        return c != s[pos - 1];
    }
    return ((c != s[pos - 1]) && (c != s[pos - 2]));
}
string getgreedy(int pos) {
    string apnd = string("");
    string ori = s.substr(0, pos);

    for(int i = pos; i < n; i++) {
        if(i == 1) {
            char r = nxt(s[i - 1]);
            s[i] = r;
            apnd += r;
        }
        else {
            char r = nxt(s[i - 1], s[i - 2]);
            s[i] = r;
            apnd += r;
        }
    }
    ori += apnd;
    return ori;
}
int main() {
    cin >> n >> p;
    limit = 'a' + p - 1;
    cin >> s;
    for(int i = n - 1; i >= 0; i--) {
        for(char c = s[i] + 1; c <= limit; c++) {
            if(isOk(i, c)) {
                s[i] = c;
                cout << getgreedy(i + 1) << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
