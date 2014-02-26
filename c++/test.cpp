
//sg
#include <stdio.h>
#include <algorithm>
#define max(a, b) (a > b ? a : b)
#define MAX 100010
int main()
{
long long int M[MAX], F[MAX];
int N = MAX;
long long int pairs = 0;
    
for(int i = 0; i < N; i++) {
    for(int j = i; j < N; j++) {
        if(F[i] > F[j]) {
            pairs++;
        }
    }
}
printf("%lld\n", pairs);
return 0;
}
