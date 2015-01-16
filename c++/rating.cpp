//sg
#include <list>
#include <stdio.h>
using namespace std;
typedef long long LL;
int main()
{
    list<LL> ratings;
    LL x = 0;
    while(1) {
        scanf("%lld", &x);
        if(x == -1) {
            break;
        }
        ratings.insert(ratings.begin(), x);
    }
    return 0;
}
