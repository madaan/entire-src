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
#define MAX 10009
int chefMax[MAX];
int dishChef[MAX];
int wasBeatenBy[MAX];
//map<int, list<int> > chefDishMap;
/**
 * Return 0 : Updates success
 * Return -1 : Invalid query
 */
/*
int handleQuery0(int dish1, int dish2) {
    int chef1 = dishChef[dish1];
    int chef2 = dishChef[dish2];
    if(chef2 == chef1) {
        return -1;
    }
    int chef1Best = chefMax[chef1];
    int chef2Best = chefMax[chef2];
    list<int> loserIndexes, winnnerIndexes;
    if(chef1Best > chef2Best) { //chef1 wins
        loserIndexes = chefDishMap[chef2];
        winnnerIndexes = chefDishMap[chef1];
        tr(loserIndexes, i) {
            dishChef[*i] = chef1;
        }
        winnnerIndexes.splice(winnnerIndexes.end(), loserIndexes);
        chefDishMap[chef1] = winnnerIndexes;
    } else if(chef1Best < chef2Best) { //chef2 wins
        //printf("chef 2 wins\n");
        loserIndexes = chefDishMap[chef1];
        winnnerIndexes = chefDishMap[chef2];
        tr(loserIndexes, i) {
            dishChef[*i] = chef2;
        }
        winnnerIndexes.splice(winnnerIndexes.end(), loserIndexes);
        chefDishMap[chef2] = winnnerIndexes;
    } //else ignore
    return 0;
}
*/

int handleQuery1(int dishNumber) {
    int realChef = dishNumber;
    while(realChef != wasBeatenBy[realChef]) {
        realChef = wasBeatenBy[realChef];
    }
    return realChef;
}

int handleQuery0(int dish1, int dish2) {
    int chef1 = handleQuery1(dish1);
    int chef2 = handleQuery1(dish2);
    if(chef2 == chef1) {
        return -1;
    }
    //path compression
    wasBeatenBy[dish1] = chef1;
    wasBeatenBy[dish2] = chef2;

    int chef1Best = chefMax[chef1];
    int chef2Best = chefMax[chef2];
    if(chef1Best > chef2Best) { //chef1 wins
        wasBeatenBy[chef2] = chef1;
    } else if(chef1Best < chef2Best) { //chef2 wins
        wasBeatenBy[chef1] =chef2;
    }
    return 0;
}

#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int main() {
    int t, n, q;
    scanf("%d", &t);
    while(t--) {
        //init
        //chefDishMap.clear();
        //memset(dishChef, 0, MAX * sizeof(int));
        memset(wasBeatenBy, 0, MAX * sizeof(int));
        //memset(chefMax, 0, MAX * sizeof(int));
    
        //get the dishes
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &chefMax[i]);
            //chefMax[i] = read_int();
            dishChef[i] = i;
            wasBeatenBy[i] = i;
            //chefDishMap[i] = list<int>(1, i);
        }
        //read queries
        scanf("%d", &q);
        int queryType, dish1, dish2;
        for(int i = 1; i <= q; i++) {
            scanf("%d", &queryType);
            if(queryType == 0) {
                scanf("%d%d", &dish1, &dish2);
                if(handleQuery0(dish1, dish2) == -1) {
                    printf("Invalid query!\n");
                }
            } else {
                scanf("%d", &dish1);
                printf("%d\n", handleQuery1(dish1));
            }
        }
    }
    return 0;
}





