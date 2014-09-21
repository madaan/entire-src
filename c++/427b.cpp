//sg
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, t, c, temp;
    vector<int> vioIndexes;
    scanf("%d%d%d", &n, &t, &c);
    vioIndexes.push_back(0);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        if(temp > t) {
            vioIndexes.push_back(i);
        }
    }
    vioIndexes.push_back(n + 1);
    int res = 0;
    int l = vioIndexes.size();
    for(int i = 1; i <= l - 1; i++) {
        int numEle = vioIndexes[i] - vioIndexes[i - 1] - 1;
        if(numEle >= c) {
            res += (numEle - c + 1);
        }
    }
    printf("%d\n", res);
    return 0;
}



