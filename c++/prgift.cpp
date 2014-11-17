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
#define MAX 60
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        int nums[MAX];
        int cums[MAX];
        int temp;
        scanf("%d%d", &n, &k);
        cums[0] = 0;
        bool someEven = false, someOdd = false;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            if(temp % 2 == 0) {
                someEven = true;
                nums[i] = 1;
            } else {
                someOdd = true;
                nums[i] = 0;
            }
            cums[i] = cums[i - 1] + nums[i];
        }
        cums[n + 1] = cums[n];
        if(k == 0) {
            if(someOdd) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            continue;
        }
        if(k == n) {
            if(cums[n] == n) {
                //printf("here cums[%d] = %d\n", n, cums[n]);
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            continue;
        }
        //try out all window sizes
        int ws;
        bool found = false;
        for(ws = k; ws <= n; ws++) {
            for(int i = 1; i <= n - ws + 1; i++) {
                if(cums[i + ws - 1] - cums[i - 1] == k) {
                    found = true;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        if(!found) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
