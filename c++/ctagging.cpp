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
    int t, n, m, a, b, temp;
    vector<pi> nums, maxm;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            nums.pu(pi(temp, i));
        }
        sort(all(nums));
        for(int i = 0; i < nums.size(); i++) {
            //cout << nums[i].second << " : " << nums[i].first << "\n";
            maxm.pu(pi(nums[i].second, nums[i].first));
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            a--;
            b--;
            //cout << "a : " << a << "b : " << b << "\n";
            res = 0;
            int found = 0;
            for(int j = maxm.size() - 1; j >= 0 && found < 2; j--) {
                if(maxm[j].first != a && maxm[j].first != b) {
                    res += maxm[j].second;
                    found++;
                }
            }
            cout << res << "\n";
        }
        return 0;
}
