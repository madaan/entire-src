//sg
#include<cstdio>
#define MAXJ 10009
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
#define max(a, b) ((a > b) ? a : b)
struct Order
{
    int start;
    int end;
    int cost;
};
typedef pair<int, Order> po;

bool compare(const po &i, const po &j)
{
    return i.first < j.first;
}

//Data Structures
int prevCompatible[MAXJ];
ll cache[MAXJ];
vector<po> orders;
vector<int> endTimes;

void makePrevCompatible2 (int n) {
    prevCompatible[0] = -1;
    for(int i = 1; i < n; i++) { //
        prevCompatible[i] = -1;
        for(int j = i - 1; j >= 0; j--) {
            if(orders[j].second.end <= orders[i].second.start) {
                prevCompatible[i] = j;
                break;
            }
        }
    }
}

int nearestBinSearch(int l, int r, int x) {
    int mid, lprev;
    lprev = l;
    while(l < r) {
        mid = l + ((r - l + 1) / 2);
        //printf("(%d - %d), mid = %d\n", l, r, mid);
        if(endTimes[mid] <= x) { //this is legal
            l = mid;
        } else {
            r = mid - 1;
        }

    }
    if(endTimes[l] > x) {
        return -1;
    }
    return l;
}


void makePrevCompatible (int n) {
    prevCompatible[0] = -1;
    for(int i = 1; i < n; i++) { //
        prevCompatible[i] = nearestBinSearch(0, i - 1, orders[i].second.start);
    }
    
}
 
ll findMaxWeight(int n) {
    if(n < 0) {
        return -1;
    }
    if(cache[n] != 0) {
        return cache[n];
    }
    int pc = prevCompatible[n];
    ll choice1 = orders[n].second.cost;
    if(pc != -1) { //noone is compatible
    choice1 += findMaxWeight(pc);
    }
    ll choice2 = findMaxWeight(n - 1);
    cache[n] = max(choice1, choice2);
    return cache[n];
}


int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        orders.clear();
        endTimes.clear();
        for(int i = 0; i < MAXJ; i++) {
            cache[i] = 0;
            prevCompatible[i] = -1;
        }
        //memset(cache, 0, sizeof(ll) * MAXJ);
        //memset(prevCompatible, 0, sizeof(int) * MAXJ);
        int st, du, p;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &st, &du, &p);
            Order o;
            o.start = st;
            o.end = st + du;
            o.cost = p;
            orders.push_back(pair<int, Order>(st + du, o));
        }
        sort(all(orders), compare);
        for(int i = 0; i < n; i++) {
            endTimes.push_back(orders[i].second.end);
        }
        makePrevCompatible(n);
        cache[0] = orders[0].second.cost;
        printf("%lld\n", findMaxWeight(n - 1));
    }
    return 0;
}


        

