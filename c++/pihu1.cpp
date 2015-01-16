//sg
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 1100
ll arr[MAX];
int bsearch(ll l, ll r, ll x) {
    ll mid;
    while(l <= r) {
        mid = (l + ((r - l) / 2));
        if(arr[mid] == x) {
            return mid;
        }
        if(arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}
int main() {
    ll t, n, p;
    bool found = false;
    scanf("%lld", &t);
    while(t--) {
        found = false;
        scanf("%lld", &n);
        for(ll i = 0; i < n; i++) {
            scanf("%lld", arr + i);
        }
        sort(arr, arr + n);
        scanf("%lld", &p);
        for(ll i = 0; i < n; i++) {
            for(ll j = i + 1; j < n; j++) {
                int loc = 0;
                if((loc = bsearch(0, n - 1, p - (arr[i] + arr[j]))) != -1) {
                    if(loc != i && loc != j) {
                        found = true;
                        break;
                    }
                    int currEle = arr[loc];
                    int l = loc + 1;
                    while(arr[l] == currEle) {
                        if(l != i && l != j) {
                            found = true;
                            break;
                        }
                        l++;
                    }
                    if(found) {
                        break;
                    }
                }
            }
        }
        if(found) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
