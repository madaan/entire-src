//sg
#include <cstdio>
#include <cassert>
#include <cstring>
//This function returns the best possible next dish given the current dish
//under the budget
int cost[51], value[51]; //storing this as a 2d array is also costly
int DAYS, NUM_DISHES, BUDGET;
#define COST 0
#define BENEFIT 1
#define max(a, b) ((a > b) ? (a) : (b))
#define EXCEEDED -1
#define INIT 0
#define INF 1000000
int cache[101][22][51][22];
int hook[101][22][51];
int menu(int budget, int day, int prev_dish, int times_prev_dish)
{
    int benifit = 0, temp;
    int &ret = cache[budget][day][prev_dish][times_prev_dish];
    if (ret != -1) {
        return ret;
    }
    /*
    if ( budget < 0) {
        return -INF;
    }
    if (budget == 0 && day > 0) {
        return -INF;
    }
    */
    if (day == 0) {
        return 0;
    }
    int maxin = -1;

    ret = -INF;

    for(int i = 1; i <= NUM_DISHES; i++) {
        int rem = budget - cost[i];
        if(rem < 0 || (rem == 0 && day - 1 > 0)) {
            continue;
        }
        if(i == prev_dish) {
            benifit =  value[i] >> 1;
            if(times_prev_dish > 1) {
                benifit = 0;
            }
            if(day - 1 == 0) {
                temp = 0;
            } else {
                temp = menu(budget - cost[i], day - 1, i, times_prev_dish + 1);
            }
        } else {
            benifit = value[i];
            if(day - 1 == 0) {
                temp = 0;
            } else {
                temp = menu(budget - cost[i], day - 1, i, 1);
            }
        }
        if(temp != -INF) {
            if(ret < benifit + temp) {
                maxin = i;
                ret = benifit + temp;
            }
        }
    }
    hook[budget][day][prev_dish] = maxin;
    //printf("hook[%d][%d][%d] = %d\n", budget, day, prev_dish, hook[budget][day][prev_dish]);
    //std::cout<<budget<<" "<<day<<" "<<prev_dish<<" "<<maxin<<" "<<ret<<std::endl;
    //std::cout << hook[budget][day][prev_dish] << "\n";
    return ret;
}

void dumpstates(int budget, int day)
{
    int n = hook[budget][day][0];
    for(int i = day - 1; i > 0; i--) {
        printf("%d ",n);
        budget = budget - cost[n];
        n = hook[budget][i][n];
    }
    printf("%d ",n);
    printf("\n");
}
int main()
{
    while(true) {
        scanf("%d%d%d",&DAYS, &NUM_DISHES, &BUDGET);
        if(DAYS == 0) {
            break;
        }
        for(int i = 1 ; i <= NUM_DISHES; i++) {
            scanf("%d%d", &cost[i], &value[i]);
        }
        for(int i = 1 ; i <= NUM_DISHES; i++) {
            value[i] = value[i] * 2;
        }
        int c = -INF, temp;
        int best;
        memset(cache, -1, sizeof(cache));
        for(int i = 1; i <= BUDGET; i++) {
            temp = menu(i, DAYS,  0, NUM_DISHES + 1);
            if(c < temp) {
                c = temp;
                best = i;
            }
        }
        if(c == -INF) {
            printf("0.0\n\n");
        } else {
            printf("%.1f\n", (float)c / 2);
            dumpstates(best, DAYS);
        }
    }
    return 0;
}

