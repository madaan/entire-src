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
#define MOD 1000000007
#define MAX 100009
int vis[MAX];
int a[MAX];
map<int, int> primeFactorMap;
// A function to print all prime factors of a given number n
void fillPrimeFactors(ll n)
{
    int count = 0; //to avoid updating the map each time
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        count++;
        n = n/2;
    }
    primeFactorMap[2] = max(count, primeFactorMap[2]);

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        count = 0;
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            count++;
            //printf("%d ", i);
            n = n/i;
        }
        primeFactorMap[i] = max(count, primeFactorMap[i]);
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        primeFactorMap[n] = max(primeFactorMap[n], 1);
}
ll lcmList(vector<ll> nums) {
    for(int i = 0; i < nums.size(); i++) {
        fillPrimeFactors(nums[i]);
    }
    ll res = 1;
    tr(primeFactorMap, i) {
        int primeNumber = i->first;
        int count = i -> second;
        for(int i = 1; i <= count; i++) {
            res = (res * primeNumber) % MOD;
        }
    }
    return res;
}
int main() {
    int t, n, temp;
    /*
    ll arr[] = {197, 201, 43, 337, 401, 503, 1193, 201, 191, 101, 243, 541, 19032, 31, 97, 53, 117, 191};
    vector<ll> nums;
    nums.assign(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    printf("%lld\n", lcmList(nums));
    return 0;
    */
    scanf("%d", &t);
    while(t--) {
        memset(vis, 0, MAX * sizeof(int));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        primeFactorMap.clear();
        bool found = false;
        int k = 1, start = 1;
        vector<long long> listLens;
        ll res = 1;
        while(true) {
            //look for something which is not yet assigned a set
            found = false;
            for(k = start; k <= n; k++) {
                if(vis[k] == 0) {
                    start = k;
                    found = true;
                    break;
                }
            }
            if(!found) { //our job is done
                break;
            }
            //printf("starting at %d\n", start);
            k = start; //overloading of notation
            ll inSet = 1;
            vis[k] = 1;
            while(a[k] != start) {
                inSet++;
                vis[a[k]] = 1;
                k = a[k];
            }
            //printf("Found %lld\n", inSet);
            //res = ((res % MOD)  * (inSet % MOD)) % MOD;
            //printf("res = %lld\n", res);
            listLens.push_back(inSet);
        }

        printf("%lld\n", lcmList(listLens) % MOD);
    }
    return 0;
}
