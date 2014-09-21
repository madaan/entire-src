
//sg
#include<bits/stdc++.h>
using namespace std;
#define MAXIDX 30009
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
vector<string> jumbled, original;
map<string, int> indexMap;
int main() {
    int t;
    char tempS[50];
    scanf("%d", &t);
    while(t--) {
        jumbled.clear();
        memset(tree, 0, sizeof(tree));
        /*
        for(map<string, int>::iterator i = indexMap.begin(); i != indexMap.end(); ) {
            map<string, int>::iterator toErase = i;
            ++i;
            printf("here");
            indexMap.erase(toErase);
        }
        */
        indexMap.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", tempS);
            jumbled.push_back(string(tempS));
        }
        for(int i = 1; i <= n; i++) {
            scanf("%s", tempS);
            indexMap[string(tempS)] = i;
        }
        for(int i = 0; i < n; i++) {
            target[i] = indexMap[jumbled[i]];
        }
        //scan through origial, creating a map
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
