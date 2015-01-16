//sg
#include<bits/stdc++.h>
using namespace std;
#define MAXIDX 10000009
int tree[MAXIDX];
int read(int idx) {
    int res = 0;
    while(idx > 0) {
        res += tree[idx];
        idx -= (idx & -idx);
    }
    return res;
}
void update(int idx, int value) {
    while(idx < MAXIDX) {
        tree[idx] += value;
        idx += (idx & -idx);
    }
}
#define maxn 200004
int arr[maxn], target[maxn];
vector<int> sorted;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(tree, 0, sizeof(tree));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            sorted.push_back(arr[i]);
        }
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < n; i++) {
            int loc = static_cast<int>(lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin());
            target[i] = loc + 1;
        }
        long long icount = 0;
        long long temp = 0;
        for(int i = n - 1; i >= 0; i--) {
            temp = read(target[i] - 1); //all the inversions for this
            update(target[i], 1);
            icount += temp;
        }
        printf("%lld\n", icount);
    }
    return 0;
}
