//sg
#include<stdio.h>
#include<string.h>
#define MAX 1000009
using namespace std;
typedef long long ll;
ll cum[MAX];
char str[MAX];
int firstOccur[MAX];
ll oc[MAX];
int main() {
    int t;
    scanf("%d", &t);
    int n, k;
    while(t--) {
        scanf("%d%d", &n, &k);
        memset(oc, 0, MAX);
        scanf("%s", str + 1);
        cum[0] = 0;
        ll res = 0;
        ll sum = 0;
        oc[0] = 1;
        for(int i = 1; i <= n; i++) {
            //cum[i] = cum[i - 1] + (str[i] - '0');
            //printf("cum[%d] = %lld\n", i + 1, cum[i + 1]);
            if(str[i] == '1') {
                sum++;
                //printf("fo[%lld] = %d\n", cum[i + 1], firstOccur[cum[i + 1]]);
            }
            if(sum >= k) {
                res += oc[sum - k];
            }
            oc[sum]++;
        }
        /*
        cum[n + 1]  = cum[n] + 1;
        firstOccur[cum[n + 1]] = n + 1;
        for(int i = 1; i <= n + 1; i++) {
            //printf("fo[%lld] = %d\n", cum[i], firstOccur[cum[i]]);
        }

        //printf("k = %d, cum[%d] = %lld\n", k, n, cum[n]);
        
        if(k > cum[n]) {
            printf("0\n");
            continue;
        }
        ll res = 0;
        for(int i = 1; i <= n; i++) {
            //printf("Searching for %lld from (%d, %d) : %d\n",  cum[i - 1] + k, i, n - 1, bsearch(i, n, cum[i - 1] + k));
            ll key = cum[i - 1] + k; //to search for
            //printf("searching for %lld\n", key);
            int start = firstOccur[key];
            int end = firstOccur[key + 1] - 1;
            if(end == -1) {
                continue;
            }
            //printf("%lld is b/w %d and %d\n", key, start, end);
            if(start == 0) {
                continue;
            }
            if(end < i) {
                continue;
            }
            if(start < i && end >= i) {
                //printf("Adding : %d\n", (end - i + 1));
                res += (end - i + 1);
            } else {
                //printf("Adding : %d\n", (end - start + 1));
                res += (end - start + 1);
            }
        }
        */
        printf("%lld\n", res);
    }
    return 0;
}






