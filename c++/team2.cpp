//sg
#include<stdio.h>
#include<algorithm>
int main() {
    char ip[1000];
    long long a[4];
    int caseNumber = 1;
    while(fgets(ip, 1000, stdin)) {
        sscanf(ip, "%lld%lld%lld%lld", &a[0], &a[1], &a[2], &a[3]);
        std::sort(a, a + 4);
        printf("Case %d: %lld\n", caseNumber++, a[3] + a[2]);
    }
    return 0;
}
