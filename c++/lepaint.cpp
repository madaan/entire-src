//sg
#include<cstdio>
#define MAXN 105
#define MAXK 105
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
 
double prob[2][MAXN][MAXK];
int modInverse[MAXN];
typedef pair<int, int> pi;
map<int, list<int>* > mulInv;

void makeMulInv(int n, int c) {
    for(int i = 0; i < c; i++) {
        list<int> *temp = new list<int>(1, 1);
        mulInv[i] = temp;
    }
    for(int i = 1; i < c; i++) {
        for(int j = 2; j < c; j++) {
            mulInv[(i *j) % c]->pu(j);
        }
    }
}

            

void updateProbs(int n, int c, int l, int r, int iter) {
    int prev, curr;
    if(iter % 2 == 0) {
        prev = 1;
        curr = 0;
    } else {
        prev = 0;
        curr = 1;
    }
    for(int i = 1; i < l; i++) {
        for(int j = 0; j < c; j++) {
            prob[curr][i][j] = prob[prev][i][j];
        }
    }
    double w = 1.0 / (2 * c);
    for(int i = l; i <= r; i++) {
        prob[curr][i][0] = prob[prev][i][0] + w;
        for(int j = 1; j < c; j++) {
          //  prob[curr][i][j] = 0.5 * prob[prev][i][j] + (1.0 / 6) * (prob[prev][i][j] + prob[prev][i][modInverse[j]]);
            double temp = 0;
            //prob[curr][i][j] = 0.5 * prob[prev][i][1] + (1.0 / 6) * (prob[prev][i][1] + prob[prev][i][modInverse[1]]);
            list<int> *mulInvsList = mulInv[j];
            tr((*mulInvsList), mi) {
                //printf("%d -> %d\n", j, *mi);
                temp += prob[prev][i][*mi];
            }
            prob[curr][i][j] = 0.5 * prob[prev][i][j] + w * (temp);
            //prob[curr][i][2] = 0.5 * prob[prev][i][2] + (1.0 / 6) * (prob[prev][i][1] + prob[prev][i][modInverse[2]]);
            //prob[curr][i][1] = 0.5 * prob[prev][i][1] + (1.0 / 6) * (prob[prev][i][1] + prob[prev][i][2]);
            //prob[curr][i][2] = 0.5 * prob[prev][i][2] + (1.0 / 6) * (prob[prev][i][1] + prob[prev][i][2]);
        }
    }
    for(int i = r + 1; i <= n; i++) {
        for(int j = 0; j < c; j++) {
            prob[curr][i][j] = prob[prev][i][j];
        }
    }
}

double getavg(int n, int c, int k) {
    double res = 0;
    int curr;
    if(k % 2 == 0) {
        curr = 0;
    } else {
        curr = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < c; j++) {
        res = res + j * prob[curr][i][j];
        }
    }
    return res;
}

int main() {
    int t;
    int n, c, k, l, r;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &c, &k);
        mulInv.clear();
        makeMulInv(n, c);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < c; j++) {
                prob[0][i][j] = 0;
            }
                prob[0][i][1] = 1;
        }
        for(int i = 1; i <= k; i++) {
            scanf("%d%d", &l, &r);
            updateProbs(n, c, l, r, i);
            //printProbs(i);
        }
        printf("%.9f\n", getavg(n, c, k));
    }
    return 0;
}
