
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
typedef vector<long long> vi;
typedef pair<long long,long long> pi;
typedef vector<string> vs;

// Basic macros
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(long long i=s;i<(n);++i)
#define rep(i,s,n)  for(long long i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(long long i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (long long)(x.size())

#define MAX 105
const long long int MOD = 1000000007;
void split(char* str, set<long long> &shirtNums)
{
    char* saveptr;
    const char *delim = " ";
    char* token = strtok_r(str, delim, &saveptr);
    while(token != NULL)
    {
        shirtNums.insert(atoi(token));
        token = strtok_r(NULL,delim,&saveptr);
    }
}

class tshirtSet {
public:
    long long a, b; //shouldn't really be public
    long long numShirts;
    set<int> shirtNums;
    tshirtSet(char *str) {
        a = 0;
        b = 0;
        char* saveptr;
        const char *delim = " ";
        numShirts = 0;
        char* token = strtok_r(str, delim, &saveptr);
        while(token != NULL)
        {
            int sn = atoi(token);
            shirtNums.insert(atoi(token));
            token = strtok_r(NULL,delim,&saveptr);
             if(sn <= 63) {
                a = a | (1LL << sn);
            } else {
                b = b | (1LL << (sn - 64));
            }
             numShirts++;
        }
    }

    void printShirts() {
        for(int i = 1; i < 64; i++) {
            if(a & (1LL << i)) {
                printf("%d\n", i);
            }
        }
        for(int i = 64; i <= 100; i++) {
            if(b & (1LL << (i - 64))) {
                printf("%d\n", i);
            }
        }
    }

    void setShirts() {
        numShirts = 0;
        shirtNums.clear();
        for(long long i = 1; i < 64; i++) {
            if(a & (1LL << i)) {
                shirtNums.insert(i);
                numShirts++;
            }
        }
        for(long long i = 64; i <= 100; i++) {
            if(b & (1LL << (i - 64))) {
                shirtNums.insert(i);
                numShirts++;
            }
        }
    }

    tshirtSet() {
        this->a = 0;
        this->b = 0;
        this->numShirts = 0;
    }

    tshirtSet(long long a, long long b, long long numShirts) {
        this->a = a;
        this->b = b;
        this->numShirts = numShirts;
    }

    tshirtSet isect(tshirtSet &s1, tshirtSet &s2) {
        return tshirtSet(s1.a & s2.a, s1.b & s2.b, min(s1.numShirts, s2.numShirts));
    }

    bool isSet(int i) {
        if(i < 64) {
            return !((a & (1LL << i)) == 0); // bitwise have lower precedence than == 
        } else {
            return !((b & (1LL << (i - 64))) == 0);
        }
    }

};
ll mod(ll a, ll m)
{
return (a % m + m) % m;
}

long long int repCount[12];
int n;
const long long oo = 2000000009;
const double eps = 1e-9;
tshirtSet shirtSets[12];

void update(int friendStr) {
    int numReps = 0;
    int reps[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long long ta, tb;
    for(int i = 1; i <= n; i++) {
        if((friendStr & (1 << (i - 1)))) {
            if(numReps == 0) { ta = shirtSets[i].a; tb = shirtSets[i].b;}
            ta = (ta & shirtSets[i].a);
            tb = (tb & shirtSets[i].b);
            numReps++;
        } else {
            reps[i] = 1;
        }
    }
    if(numReps < 2 || (ta == 0 && tb == 0)) {
        return;
    }
    tshirtSet temp(ta, tb, 0);
    temp.setShirts();
    long long val = 0;
    tr(temp.shirtNums, repeatedT) {
        long long tval = 1;
        for(int i = 1; i <= n; i++) {
            if(reps[i] == 1) { //need to process this
                if(!shirtSets[i].isSet(*repeatedT)) {
                    //prlong longf("here");
                    tval = mod(tval * shirtSets[i].numShirts, MOD);
                } else {
                    tval = mod((tval * (shirtSets[i].numShirts - 1)) , MOD);
                }
            }
        }
        //prlong longf("For repeated %d, %lld\n", *repeatedT, tval);
        val = mod(val  + tval, MOD);
    }
    printf("%d => %lld\n", numReps, val);
    repCount[numReps] = mod(repCount[numReps] + val, MOD);
}

typedef unsigned long long ull;
ll res;
int tmap[110];
void ways(int int k) {
    if(k == n + 1) {
        res = mod(res + 1, MOD);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(shirtSets[k].isSet(i) && (tmap[i] == 0)) {
            tmap[i] = 1;
            ways(k + 1);
            tmap[i] = 0;
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        cin.ignore();
        for(int i = 0; i <= 10; i++) {
            repCount[i] = 0;
        }
        memset(tmap, 0, sizeof(tmap[0]) * 110);
        long long totalPossib = 1;
        for(long long i = 1; i <= n; i++) {
            size_t l;
            //cin.getline(str, '\n');
            //char str[2000];
            //fgets(str, 2000, stdin);
            char *str = NULL;
            getline(&str, &l, stdin);
            //prlong longf("%d - > \n", i);
            shirtSets[i] = tshirtSet(str);
            totalPossib = mod(totalPossib * shirtSets[i].numShirts, MOD);
        }
        res = 0;
        ways(1);
        printf("%lld\n", res);
    }
    return 0;
}

