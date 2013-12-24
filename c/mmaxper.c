//sg
#include <stdio.h>
#define S 0
#define L 1

#define abs(x) (x > 0 ? (x) : -(x))
#define max(a, b) ((a > b) ? a : b)

//peri [i][L] means the total maximum perimeter till the top
//face of the ith rectangle with its larger side up
int peri[1020][2];
int sides[1020][2];
int n;
void max_rect()
{
    int i;
    peri[0][S] = sides[0][S];
    peri[0][L] = sides[0][L];
    for(i = 1; i < n; i++) {
        //printf("(r%d, %c, %d)\n", i - 1, 'S', peri[i - 1][S]);
        //printf("(r%d, %c, %d)\n", i - 1, 'L', peri[i - 1][L]);
        peri[i][S] = sides[i][S] + 
            max(abs(sides[i][L] - sides[i - 1][L]) + peri[i - 1][S], 
                abs(sides[i][L] - sides[i - 1][S]) + peri[i - 1][L]); 

        peri[i][L] = sides[i][L] + 
            max(abs(sides[i][S] - sides[i - 1][L]) + peri[i - 1][S], 
                abs(sides[i][S] - sides[i - 1][S]) + peri[i - 1][L]); 
    }
        //printf("(r%d, %c, %d)\n", i - 1, 'S', peri[i - 1][S]);
        //printf("(r%d, %c, %d)\n", i - 1, 'L', peri[i - 1][L]);

}

int main()
{
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d%d", &sides[i][S], &sides[i][L]);
    }
    max_rect();
    printf("%d\n", max(peri[n - 1][S], peri[n - 1][L]));
    return 0;
}
