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
int cnt[3000];
int main() {
    int n, tmp;
    cin >> n;
    vector<pi> nums;
    int r1 = -1, r2 = -1, reps = 0;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        nums.push_back(pi(tmp, i));
        cnt[tmp]++;
        if(reps < 2 && cnt[tmp] >= 2) {
            reps++;
            if(reps == 1) {
                r1 = tmp;
            } else {
                r2 = tmp;
            }
        }
    }
    if(reps < 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    sort(all(nums));
    int l = nums.size();
    fr(i, l) {
        cout << nums[i].second << " ";
    }
    cout << "\n";
    bool done = false;
    int flippedAt = 0;
    for(int i = 0; i < l; i++) {
        if(!done && nums[i].first == r1) {
            done = true;
            flippedAt = i;
            cout << nums[i + 1].second << " " << nums[i].second << " ";
            i++;
        } else {
            cout << nums[i].second << " ";
        }
    }
    cout << "\n";
    done = false;
    if(r1 != r2) {
        for(int i = 0; i < l; i++) {
            if(!done && nums[i].first == r2) {
                done = true;
                cout << nums[i + 1].second << " " << nums[i].second << " ";
                i++;
            } else {
                cout << nums[i].second << " ";
            }
        }
    } else {
        for(int i = 0; i < l; i++) {
            if(!done && flippedAt != i &&  nums[i].first == r2) {
                done = true;
                cout << nums[i + 1].second << " " << nums[i].second << " ";
                i++;
            } else {
                cout << nums[i].second << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}
