//sg
#include <stdio.h>
int prediction[1500009];

void fillPrediction(int N, int s, int t) {
    int i;
    prediction[0] = (s % 100 + 1) * (t % 100 + 1);
    for(i = 1; i <= N; i++) { 
        s = (78901 + 31*s) %  699037;
        t = (23456 + 64*t) % 2097151;
        prediction[i] = (s % 100 + 1) * (t % 100 + 1);
    }
}

int main()
{
    int i, N, s, t, M, K;
    int lW, rW;
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d%d%d%d", &s, &t, &N, &M);
        /*fill up the array*/
        //fillPrediction(N, s, t);
        prediction[0] = (s % 100 + 1) * (t % 100 + 1);
        for(i = 1; i <= N; i++) { 
            s = (78901 + s * ((1 << 5) - 1)) %  699037;
            t = (23456 + t * (1<<6)) % 2097151;
            prediction[i] = (s % 100 + 1) * (t % 100 + 1);
        }
        lW = rW = 1;
    
        long long sum = 0;
        /*First find out some initial value for K*/
        do {
            sum += prediction[rW];
            rW++;
        } while(rW <= N && sum + prediction[rW] <= M);
       
        K = rW - lW;
        //now process the rest of the array
    
        while(rW <= N) { 
            //find the range till which the value of K holds
            while(rW <= N && sum <= M)
            {
                //printf("lW = %d, rW = %d\n", lW, rW);
                sum = sum - prediction[lW] + prediction[rW];
                lW++;
                rW++;
            }
            //lW invariant is now broken. newSum = sum(prediction[lW:rW] with *both* included)
            //either K should be updated or processing is over
            if(rW > N) {
                break;
            } else { //need to update K
                while(sum > M) {
                    sum = sum -  prediction[lW];
                    lW++;
                    K--;
                }
            }
        }
        printf("%d\n", K);
    }
    return 0;
    }
        
