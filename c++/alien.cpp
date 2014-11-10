//sg
#include<stdio.h>
using namespace std;
typedef long long ll;
#define MAX 100009
int people[MAX];
ll cumPeople[MAX];
#define Int(x) int x; scanf("%d", &x);
/**
 * Returns the best sequence that the alien can take
 */
ll getLongStationSeq(ll At, ll Bt) {
    ll peopleSeenBest, numStationsBest, peopleSeen, numStations;
    ll left = 0, right = 0, temp;
    int bestLeft = 0, bestRight = 0;
    peopleSeen = 0;
    numStations = 0;
    peopleSeenBest = 0;
    numStationsBest = 0;
    while(right < At) {
        while(left < right) {
            if((peopleSeen - people[left] + people[right]) < Bt) {
                peopleSeen = peopleSeen - people[left];
                left++;
                break;
            }
            peopleSeen = peopleSeen - people[left];
            left++;
        }
        //printf("After Left C: left = %lld right = %lld\n", left, right);
        if(left == right) {
            while(left < At) {
                if(people[left] <= Bt) {
                    break;
                }
                left++;
                right = left;
            }
        }
        if(right >= At) {
            break;
        }
        /*Expand a window to right*/
        //the variable right is the edge to be tested
        //printf("After Equal C: left = %lld right = %lld\n", left, right);
        while(peopleSeen <= Bt && right < At) {
            temp = peopleSeen + people[right];
            if(temp > Bt) {
                break;
            }
            right++;
            peopleSeen = temp;
        }
        //printf("Num stations : %lld\n", numStations);
        //printf("After Right E: left = %lld right = %lld\n", left, right);
        //now right is something which does not satisfy the required criterion
        //update best scores if needed
        numStations = right - left;
        if(numStationsBest < numStations || (numStations == numStationsBest && peopleSeen < peopleSeenBest)) { //updated?
            bestLeft = left;
            bestRight = right - 1;
            numStationsBest = numStations;
            peopleSeenBest = peopleSeen;
        }

    }
    if(bestLeft == 0) {
        peopleSeenBest = cumPeople[bestRight];
    } else {
        peopleSeenBest = cumPeople[bestRight] - cumPeople[bestLeft - 1];
    }
    printf("%lld %lld\n",peopleSeenBest, numStationsBest);
}
int main() {
    Int(t);
    while(t--) {
        Int(At);
        Int(Bt);
        scanf("%d", &people[0]);
        cumPeople[0] =  people[0];
        for(int i = 1; i < At; i++) {
            scanf("%d", &people[i]);
            cumPeople[i] = cumPeople[i - 1] + people[i];
        }
        getLongStationSeq(At, Bt);
    }
    return 0;
}

