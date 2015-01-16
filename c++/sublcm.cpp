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
ll gcd (ll a, ll b )
{
    ll c;
    while ( a != 0 ) {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
ll dp[100009];
// A function to print all prime factors of a given number n
set<int> primeFactors(int n)
{
    set<int> primes;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        primes.insert(2);
        n = n/2;
    }
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            primes.insert(i);
            n = n/i;
        }
    }
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        primes.insert(n);
    return primes;
}
int main3() {
    int t, n, temp;
    scanf("%d", &t);
    while(t--) {
        vector < set<int> > primes;
        set<int> primesTill;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            primes.push_back(primeFactors(i));
        }
    }
}
int main() {
    int t, n, temp;
    scanf("%d", &t);
    int arr[100009];
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        ll ans = -1;
        scanf("%d", &arr[1]);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            scanf("%d", &arr[i]);
            ll res = 1;
            for(int j = i - 1; j >= dp[i - 1]; j--) {
                if(gcd(arr[i], arr[j]) == 1) {
                    //cout << "here i = " << i << "\n";
                    res++;
                } else {
                    dp[i] = j + 1;
                    break;
                }
            }
            ans = max(res, ans);
        }
        printf("%lld\n", ans == 1 ? -1 : ans);
    }
    return 0;
}
int main1() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        ll ans = -1;
        int a;
        scanf("%d", &a);
        int gcdtill = a;
        dp[1] = 1;
        bool e = false;
        if(a % 2 == 0) {
            e = true;
        }
        for(int i = 2; i <= n; i++) {
            scanf("%d", &a);
            gcdtill = gcd(gcdtill, a);
            //cout << "gcdtill " << gcdtill << "\n";
            if(gcdtill == 1 && (a % 2 != 0 || a % 2 == 0 && !e)) {
                dp[i] = dp[i - 1] + 1;
            } else {
                gcdtill = a;
                dp[i] = 1;
                e = false;
            }
            if(a % 2 == 0) {
                e = true;
            }
            ans = max(ans, dp[i]);
        }
        printf("%lld\n", ans == 1 ? -1 : ans);
    }
    return 0;
}
