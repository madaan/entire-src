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
#define MAX 100009
long long ccount[26];
int main() {
    int n, k;
    char cards[MAX];
    scanf("%d%d", &n, &k);
    scanf("%s", cards);
    for(int i = 0; i < n; i++) {
        ccount[cards[i] - 65]++;
    }
    sort(ccount, ccount + 26, std::greater<int>());
    long long cardsLeft = k;
    unsigned long long value = 0;
    int atC = 0;
    while(cardsLeft > 0) {
        if(ccount[atC] < cardsLeft) {
            value = value + (ccount[atC] * ccount[atC]);
            cardsLeft = cardsLeft - ccount[atC];
        } else {
            value = value + (cardsLeft * cardsLeft);
            cardsLeft = 0;
        }
        atC++;
    }
    cout << value << "\n";
    return 0;
}
