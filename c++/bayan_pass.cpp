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
int ck[500];
char str[100];
bool isspecial(char c) {
    char pat[] = "!@#$%^&*()";
    for(int i = 0; i < 11; i++) {
        if(c == pat[i]) {
            return true;
        }
    }
    return false;
}

int getc() {
    int condSat = 0;
    int l = strlen(str);
    string s(str);
    for(int i = 0; i < 400; i++) {
        ck[i] = 0;
    }
    if(l >= 6) {
        condSat++;
    }
    if(l > 10) {
        condSat++;
    }   
    bool unq = true;
    bool hasUpper = false;
    bool hasLower = false;
    bool alpha = false;
    bool digit = false;
    bool hasSpl = false;
    for(int i = 0; i < l; i++) {
        if(isspecial(str[i])) {
                hasSpl = true;
        }
        if(isalpha(str[i])) {
            alpha = true;
        }
        if(isdigit(str[i])) {
            digit = true;
        } 
        if(isupper(str[i])) {
            hasUpper = true;
        }
        if(islower(str[i])) {
            hasLower = true;
        }
        if(ck[str[i]] == 1) {
            unq = false;
        } else {
            ck[str[i]] = 1;
        }
    }
    if(hasSpl) {
        condSat++;
    }
    if(alpha) {
        condSat++;
    } 
    if(digit) {
        condSat++;
    }
    if(unq) {
        condSat++;
    }
    if(hasLower && hasUpper) {
        condSat++;
    }
    return condSat;
}



int main() {
    int t;
    scanf("%d", &t);
    int i = 1;
    while(t--) {
        scanf("%s", str);
        int cons = getc();
        printf("Case #%d:\n", i++);
        //printf("cons : %d\n", cons);    
        if(cons < 4) {
            printf("weak\n");
        } else if(cons >= 6) {
            printf("strong\n");
        } else {
            printf("normal\n");
        }
    }
    return 0;
}

