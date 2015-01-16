#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
long long * tree;
long long MaxVal;
long long read(long long idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(long long idx ,long long val) {
    while (idx <= MaxVal) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int main()
{
    long long casen;
    scanf("%lld", &casen);
    for(long long c=1; c<=casen; ++c)
    {
        long long n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        MaxVal = m;
        tree = new long long[MaxVal+1];
        memset(tree, 0, sizeof(long long)*(MaxVal+1));
        vector<pair<long long, long long> > bridges(k);
        for(long long i=0; i<k; ++i)
        {
            long long e, w;
            scanf("%lld %lld", &e, &w);
            bridges[i] = pair<long long,long long>(e, w);
        }
        sort(bridges.begin(), bridges.end());
        long long sum = 0;
        for(long long i=0; i<k; ++i)
        {
            update(bridges[i].second, 1);
            sum += read(MaxVal) - read(bridges[i].second);
        }
        printf("Test case %lld: %lld\n", c, sum);
    }
}
