//sg
#include <stdio.h>
#define MAXDISH 52
#define MAXDAYS 25
#define COST 0
#define BENIFIT 1
#define max(a, b) ((a > b) ? (a) : (b))
#define EXCEEDED -1
#define INIT 0
float B[MAXDISH][MAXDAYS][MAXDISH]; //total benefit
float C[MAXDISH][MAXDAYS][MAXDISH]; //total cost
int prev[MAXDISH][MAXDAYS][MAXDISH]; //the dish cooked on the previous day
float dishInfo[55][2]; //information about the dishes
int dish_sequence[55];
bool budget_condition(float a, float budget, int day, int DAYS) {
    if(day == DAYS - 1) {
        return a <= budget;
    } else {
        return a < budget;
    }
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
        for(int i = 1; i <= NUM_DISHES; i++) {
            for(int j = 0; j < DAYS; j++) {
                B[i][j] = INIT;
            }
        }
        //initialize dishes for day 0
        for(int dish = 1; dish <= NUM_DISHES; dish++) {
            B[dish][0] = dishInfo[dish][BENIFIT];
            C[dish][0] = dishInfo[dish][COST];
            prev[dish][0] = dish + 1 % NUM_DISHES;
        }
        for(int day = 1; day < DAYS; day++) {//for all day s
            for(int dish_c = 1; dish_c <= NUM_DISHES; dish_c++) {
                for(int dish_p = 1; dish_p <= NUM_DISHES; dish_p++) {
                    if(B[dish_p][day - 1] == EXCEEDED) {
                        B[dish_c][day] = EXCEEDED;
                        continue;
                    }
                    if(budget_condition(C[dish_p][day - 1] + dishInfo[dish_c][COST],  BUDGET, day, DAYS)) { //fits in budget
                        //benefit will vary
                        if(dish_c == dish_p) {
                            if(dish_p == prev[day - 1][dish_p]) {
                                benefit = 0; //third or greater
                            } else { //need to halve
                                benefit = dishInfo[dish_c][BENIFIT] * 0.5;
                            }
                        } else {
                            benefit = dishInfo[dish_c][BENIFIT];
                        }
                        if(B[dish_c][day] <  B[dish_p][day - 1] + benefit) {
                            //printf("Replacing B[%d][%d] = %f (from dish %d)  with %f (dish %d)\n",
                            //         dish_c, day, B[dish_c][day], prev[dish_c][day], B[dish_p][day - 1] + benefit, dish_p);
                            B[dish_c][day] =  B[dish_p][day - 1] + benefit;
                            //printf("%f\n", B[2][1]);
                            C[dish_c][day] = C[dish_p][day - 1] + dishInfo[dish_c][COST];
                            prev[dish_c][day] = dish_p;
                        } else if(B[dish_c][day] ==  B[dish_p][day - 1] + benefit) {
                            if(C[dish_c][day] > C[dish_p][day - 1] + dishInfo[dish_c][COST]) { //update
                                prev[dish_c][day] = dish_p;
                                C[dish_c][day] = C[dish_p][day - 1] + dishInfo[dish_c][COST];
                            }
                        }
                    } else if(B[dish_c][day] == INIT) {
                        B[dish_c][day] = EXCEEDED;
                    }
                }
            }
        }
        float max_dish = -2  //so that it picks up -1
                         , min_cost = 10000000;
        for(int i = 1; i <= NUM_DISHES /2; i++) {
            for(int j = 6; j < 7 ; j++) {
                printf("%5f      ", C[i][j]);
            }
            printf("\n");
        }
        int hook = 0;
        for(int i = 1; i <= NUM_DISHES; i++) {
            if(max_dish < B[i][DAYS - 1]) {
                max_dish = B[i][DAYS - 1];
                min_cost = C[i][DAYS - 1];
                hook = i;
            } else if(max_dish == B[i][DAYS - 1]) {
                if(min_cost > C[i][DAYS - 1]) {
                    min_cost = C[i][DAYS - 1];
                    hook = i;
                }
            }
        }
        if(max_dish == EXCEEDED) {
            printf("0.0\n\n");
        } else {
            printf("%.1f\n", max_dish);
            for(int i = DAYS - 1; i >= 0; i--) {
                dish_sequence[i] = hook;
                hook = prev[hook][i];
            }
            for(int i = 0; i < DAYS; i++) {
                printf("%d ", dish_sequence[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
