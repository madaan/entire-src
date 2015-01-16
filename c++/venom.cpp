//sg
#include<stdio.h>
#include<math.h>
typedef long long ll;
double surviesTill(int H, int P, int A) {
    double a = P;
    double b = (P - (2 * A));
    double c = 2 * (A - H);
    double d = b * b - 4 * a * c;
    double sqrtd = sqrt(d);
    double root1 = (-1 * b + sqrtd) / (2 * a);
    //printf("root1 = %f, root2 = %f\n", root1, root2);
    return ceil(root1);
}
int main() {
    int t, H, P, A;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &H, &P, &A);
        if(H <= P) {
            printf("1\n");
            continue;
        }
        ll res = surviesTill(H, P, A);
        printf("%lld\n", ((2 * res) - 1));
    }
    return 0;
}
