//sg
#include <map>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;
map<PII, LL> cache;

LL gcd(LL a, LL b)
{
    while (b > 0)
    {
        LL temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}
int N, *input, total = 0;
LL sets(int pos, int curGCD)
{
    if(pos == N) {
        return (curGCD == 1) ? 1 : 0;
    }
    PII key = make_pair(pos, curGCD);
    if(cache.find(key) != cache.end()) {
        return cache[key];
    } else {
        cache[key] = sets(pos + 1, gcd(curGCD, input[pos])) + sets(pos + 1, curGCD);
    }
    return cache[key];
}
LL gcdAgg(int *input,LL l)
{
    LL result = input[0];
    for(LL i = 1; i < l; i++) result = gcd(result, input[i]);
    return result;
}
int main()
{
    int t, arr[60];
    scanf("%d", &t);
    while(t--) {
        int i = 0;
        scanf("%d", &N);
        while(i < N) {
            scanf("%d", &arr[i++]);
        }
        cache.clear();
        input = arr;
        printf("%lld\n", sets(0, 0));
        total = 0;
    }
    return 0;
}
