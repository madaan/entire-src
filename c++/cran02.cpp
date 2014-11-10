//sg
#include<stdio.h>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
#define MAX 1000009
#define OFFSET 10000000
ll arr[MAX];
ll cum[MAX];
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
map<ll, set<ll>*> indexMap; //stores the indexes which store a particular value
int main() {
    int t;
    ll n;
    set<ll> *temp;
    ll sum = 0;
    scanf("%d", &t);
    while(t--) {
        sum = 0;
        ll res = 0;
        map<ll, set<ll>*>::iterator loc;
        scanf("%lld", &n);
        arr[0] = cum[0] = 0;
        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &arr[i]);
            cum[i] = (sum + (arr[i] + OFFSET)) - OFFSET * i;
            sum = sum + arr[i] + OFFSET;
            //printf("cum[%lld] = %lld\n", i, cum[i]);
            loc = indexMap.find(cum[i]);
            if(loc == indexMap.end()) { //first time
                set<ll> *t = new set<ll>;
                t->insert(i);
                indexMap[cum[i]] = t;
            } else {
                //printf("here for i = %lld\n", i);
                temp = (*loc).second;
                temp->insert(i);
            }
        }
        //add for zero
        loc = indexMap.find(0);
        if(loc == indexMap.end()) { //first time
            set<ll> *t = new set<ll>;
            t->insert(0);
            indexMap[0] = t;
        } else {
            //printf("here for i = %lld\n", i);
            temp = (*loc).second;
            temp->insert(0);
        }
        /*
        for(ll i = 1; i <= n; i++) {
            if((loc = indexMap.find(cum[i - 1])) != indexMap.end()) {
                temp = (*loc).second;
                tr(*temp, j) {
                    if((*j) >= i) {
                        res++;
                    }
                }
            }
        }
        */
        ll listSz = 0;
        tr(indexMap, i) {
            temp = (*i).second;
            listSz = temp->size();
            res += ((listSz * (listSz - 1)) / 2);
        }

        /*
        tr(indexMap, i) {
            temp = (*i).second;
            printf("%lld -> ", (*i).first);
            tr(*temp, j) {
                printf("%lld ", *j);
            }
            printf("\n");
        }
        */
        indexMap.clear();
        printf("%lld\n", res);
    }
    return 0;
}
