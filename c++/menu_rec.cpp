//sg
#include <stdio.h>

float dishInfo[55][2]; //information about the dishes
int dish_sequence[55];
int DAYS, NUM_DISHES, BUDGET;
float menu[25][
#define EXCEEDED -1
#define COST 0
#define BENIFIT 1
#define max(a, b) ((a > b) ? (a) : (b))
//the state is defined by 

float menu(int day, int dish, double budget, int prev_dish)
{
    if(budget < 0) {
        return EXCEEDED;
    }
    float netBenefit = 0;
    for(int i = 1; i <= NUM_DISHES; i++) {
        if(i == dish) {
            netBenefit = dishInfo[i][BENIFIT] * 0.5;
            if(prev_dish == dish) {
                netBenefit == 0;
            }
        }

        if(day == DAYS - 1) { //last day, stop recursion
            return netBenefit;
        }

        //now recurse
        val = menu(day + 1, i, budget - dishInfo[i][COST], dish);
}


int main()
{
    int DAYS, NUM_DISHES, BUDGET;
    float benefit;
    while(true) {

        scanf("%d%d%d", &DAYS, &NUM_DISHES, &BUDGET);
        if(DAYS == 0) {
            break;
        }
        for(int i = 1; i <= NUM_DISHES; i++) {
            scanf("%f%f", &dishInfo[i][COST], &dishInfo[i][BENIFIT]);
        }
    
 
        }

        }
 
