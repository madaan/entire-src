//sg
#include <stdio.h>
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
#define MAX 1000010
#define MAXVAL 25001
int arr[MAX];
int freqcount[MAXVAL];
int main()
{
    int n, k, l, r;
    scanf("%d%d", &n, &k);
    rep(i, 1, k) {
        scanf("%d%d", &l, &r);
        arr[l]++;
        arr[r + 1]--;
    }
    //fr(i, n) printf("%d ", arr[i]);
    //now create the cumulative frequency table
    rep(i, 1, n) {
        arr[i] = arr[i] + arr[i - 1];
        freqcount[arr[i]]++;
    }

    int scanned = 0;
    int halfway = (n + 1) / 2;
    rep(i, 0, k) {
        scanned += freqcount[i];
        if(scanned >= halfway) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
