
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
    int n, k;
    cin >> n >> k;
    vector< int > hts(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> hts[i];
    }
    int m = 0;
    vector< pi > moves;
    while(m < k) {
        int minPos = min_element(hts.begin() + 1, hts.end()) - (hts.begin());
        int maxPos = max_element(hts.begin() + 1, hts.end()) - (hts.begin());
        int minEle = hts[minPos];
        int maxEle = hts[maxPos];
        if(abs(minEle - maxEle) < 2) {
            break;
        }
        moves.pu(pi(maxPos, minPos));
        hts[minPos]++;
        hts[maxPos]--;
        m++;
    }
    /*
    for(int i = 1; i <= n; i++) {
        cout << hts[i] << " ";
    }
    cout << "\n";
    */
        int minPos = min_element(hts.begin() + 1, hts.end()) - (hts.begin());
        int maxPos = max_element(hts.begin() + 1, hts.end()) - (hts.begin());
        //cout << minPos << "\n";
        //cout << maxPos << "\n";
        int minEle = hts[minPos];
        int maxEle = hts[maxPos];
  cout << maxEle - minEle << " " << m << "\n";   
    for(int i = 0, l = moves.size(); i < l; i++) {
        cout << moves[i].first << " " << moves[i].second << "\n";
    }
    return 0;
}



