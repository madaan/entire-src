//sg
#include<stdio.h>
#include<string.h>
#define MAX 1000009
using namespace std;
typedef long long ll;
ll cum[MAX];
char str[MAX];
ll oc[MAX];
int main() {
    int t;
    scanf("%d", &t);
    int n, k;
    while(t--) {
        scanf("%d%d", &n, &k);
        memset(oc, 0, MAX);
        scanf("%s", str + 1);
        oc[0] = 1;
        ll sum = 0;
        ll res = 0;
        for(int i = 1; i <= n; i++) {
            if(str[i] == '1') {
                sum++;
            }
            if(sum >= k) {
                res += oc[sum - k];
            }
            oc[sum]++;
        }
        printf("%lld\n", res);
    }
    return 0;
}
