//sg
#include <stdio.h>
typedef long long LL;
int analyze(int *arr, LL i) {
    int t;
    while(i) {
        t = i % 10;
        if(t != 5 && t != 8 && t != 3) {
            return 0;
        }
        arr[t]++;
        i /= 10;
    }
    return 1;
}

bool cielNumber(int *arr) {
    if(arr[8] >= arr[5] && arr[5] >= arr[3]) {
        //if(!arr[0] && !arr[1] && !arr[2] && !arr[4] && !arr[6] && !arr[7] && !arr[9]) {
            return true;
        //}
    }
    return false;
}


int main()
{
    LL i =  1;
    int count = 0;
    int dig[10];
    while(count < 50000) {
        for(int j = 0; j < 10; j++) {
            dig[j] = 0;
        }
        if(analyze(dig, i)) {
            //printf("Testing %lld\n", i);
            if(cielNumber(dig)) {
                printf("%lld\n", i);
                count++;
            }
        }
        i++;
    }
    return 0;
}



    
