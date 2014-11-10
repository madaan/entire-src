//sg
#include <stdio.h>
#include <algorithm>
#define max(a, b) (a > b ? a : b)
#define MAX 100010
using namespace std;
const int MAXn = 10000;
const int MAXK = 10;
typedef long long T;
T cumBIT[MAXK][MAXn+10];
T howMany[MAXK][MAXn+10];
vector<int> values;
map<int,int> mapIndex;
T dp[MAXn][MAXK];
void update(int idx, int k, int n, T val)
{
    while(idx<n) {
        cumBIT[k][idx]+=val;
        idx+=(idx&-idx);
    }
}

T getValue(int idx, int k)
{
    T ret = 0;
    while(idx>0) {

        ret+=cumBIT[k][idx];

        idx-=(idx& (-idx));
    }
    return ret;
}

int main()
{
    memset(cumBIT,0,sizeof(cumBIT));
    long long int M[MAX], values[MAX];
    int n;
    long long int pairs = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld", &M[i], &values[i]);
    }

    vector<int> temp=values;

    sort(values.begin(),values.end());
    mapIndex[values[0]]=1;
    for(int i=1; i<n; i++) {
        if(values[i]!=values[i-1]) {
            mapIndex[values[i]]=i+1;
        }
    }

    values=temp;
    T ret = 0;
    for(int i=0; i<n; i++) {
        int index = mapIndex[values[i]];
        howMany[1][i]=1;
        update(index,1,n,howMany[1][i]);
        for(int j=2; j<=k; j++) {
            howMany[j][i]=getValue(index-1,j-1);
            update(index,j,n,howMany[j][i]);
        }
        ret+=howMany[k][i];
    }

    printf("%lld\n", ret);
    return 0;
}
