
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
int main() {
    int t, tmp;
    cin >> t;
    for(int caseNum = 1; caseNum <= t; caseNum++) {
        cout << "Case #" << caseNum << ": ";
        int arng1[17], arng2[17];
        int ans1, ans2;
        cin >> ans1;
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                cin >> tmp;
                arng1[tmp] = i;
            }
        }
        cin >> ans2;
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                cin >> tmp;
                arng2[tmp] = i;
            }
        }
        /*bad magician*/
        int samepos = 0;
        /*Volunteer cheated*/
        bool found = false;
        int ans = -1;
        for(int i = 1; i <= 16; i++) {
            if(arng1[i] == ans1 && arng2[i] == ans2) {
                ans = i;
                found = true;
                samepos++;
            }
        }
        if(samepos > 1) {
            cout << "Bad magician!\n";
        } else if(!found) {
            cout << "Volunteer cheated!\n";
        } else {
            /*Alright!*/
            cout << ans << "\n";
        }
    }
    return 0;
}



