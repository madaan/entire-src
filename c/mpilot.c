//sg
#include <stdio.h>
typedef long long int lint;
#define min(x, y) (x > y ? (y) : (x))

/*DS*/
int PS[10009], CPS[10009];
lint sum_PS[10009], sum_CPS[10009];
int N;
lint cache[5010][5010];

//pilots : #pilots regarding whom the decision has been taken

lint min_cost_iter() {
    int i, j, index;
    for(i = 1; i <= N / 2; i++) { 
        cache[0][i] = sum_CPS[i - 1];
        cache[i][0] = sum_PS[i - 1];
    }
    for(i = 1; i <= N / 2 - 1; i++) { //the pilots
        for(j = i; j <= N / 2; j++) { //the co pilot for given number of pilots
            index = i + j - 1;
            if(i == j) {
                cache[i][j] = cache[i - 1][j] + PS[index];
            } else {
                cache[i][j] = min(PS[index] + cache[i-1][j], CPS[index] + cache[i][j - 1]);
            }
        }
    }
        
    return cache[N/2 - 1][N/2] + PS[N - 1];
}

lint min_cost(int pilots, int co_pilots)
{
    if(cache[pilots][co_pilots] != 0) {
        return cache[pilots][co_pilots];
    }
    //printf("min_cost(%d, %d)\n", pilots, co_pilots);
    int index = pilots + co_pilots - 1;
    if(pilots == 0) {
        cache[pilots][co_pilots] =  sum_CPS[index];
    } else if(co_pilots == 0) {
        cache[pilots][co_pilots] =  sum_PS[index];
    } else if(co_pilots == pilots) {
        if(cache[pilots - 1][co_pilots] == 0) {
            cache[pilots - 1][co_pilots] =  min_cost(pilots - 1, co_pilots);
        } 
        cache[pilots][co_pilots] = PS[index] + cache[pilots - 1][co_pilots];
    } else { 
        lint term1, term2;
        if(cache[pilots - 1][co_pilots] == 0) {
            cache[pilots - 1][co_pilots] = min_cost(pilots - 1, co_pilots);
        }
        if(cache[pilots][co_pilots - 1] == 0) {
            cache[pilots][co_pilots - 1] = min_cost(pilots, co_pilots - 1);
        }
        term1 = PS[index] + cache[pilots - 1][co_pilots];
        term2 = CPS[index] + cache[pilots][co_pilots - 1];
        cache[pilots][co_pilots] = min(term1, term2);
    }
    return cache[pilots][co_pilots];
}

int main()
{
    int i;
    scanf("%d", &N);
    scanf("%d%d", &PS[0], &CPS[0]);
    sum_PS[0] = PS[0];
    sum_CPS[0] = CPS[0];
    for(i = 1; i < N; i++) { 
        scanf("%d%d", &PS[i], &CPS[i]);
        //fastRead_int(&PS[i]);
        //fastRead_int(&CPS[i]);
        sum_PS[i] = sum_PS[i - 1] + PS[i];
        sum_CPS[i] = sum_CPS[i - 1] + CPS[i];
    }
    printf("%lld\n", min_cost_iter());
    return 0;
}
