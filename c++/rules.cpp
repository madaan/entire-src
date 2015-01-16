//sg
#include<stdio.h>
struct ConditionActionPair {
    int ruleNumber;
    bool (*comp)(int, int);
    void (*action)(int);
};
bool countryMatchCondition(int a, int b) {
    if(a == b / 2) {
        return true;
    }
    return false;
}
void countryMatchAction(int a) {
    printf("Matched country\n");
}
int main() {
    ConditionActionPair capairs[] = {{countryMatchCondition, countryMatchAction}};
    int l = 1;
    int arg1 = 4, arg2 = 8;
    for(int i = 0; i < l; i++) {
        if(capairs[0].comp(arg1, arg2)) {
            printf("here %d %d", arg1, arg2);
            capairs[0].action(arg1);
        }
    }
    return 0;
}
