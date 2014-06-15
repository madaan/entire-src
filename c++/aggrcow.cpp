//sg
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<long long> vll;
typedef long long ll;
#define pb push_back
#define all(x) (x.begin(), x.end())
#define MAX 100009
long long location[MAX];
int N, C;

bool isSpacingPossible(ll spacingNeeded) {

    ll currSpacing, placed = 1;
    int prev_position = 0, i = 1;
    while(i < N && placed < C) {
        currSpacing = location[i] - location[prev_position];
        //printf("Currspace = %lld\n", currSpacing);
        if(currSpacing >= spacingNeeded) {
            placed++;
            prev_position = i;
            currSpacing = 0;
        }
        i++;
    }
    //printf("Needed = %lld, Placed = %lld, C = %d\n", spacingNeeded, placed, C);
    return (placed == C);
}


//Spacing can vary from 0 to N - 1, test all of these pragmatically
ll leastPossibleSpacing() {
    ll min = 0, max = location[N - 1];
    while(min < max - 1) {
        ll mid = (max + min) / 2;
        //printf("checking if %lld is possible\n", mid);
        bool midFlag = isSpacingPossible(mid);
        //printf("Spacing od %lld is possible = %d\n", mid, midFlag);
        if(!midFlag) {
            max = mid;
        } else {
            min = mid;
        }
        //printf("max = %lld, min = %lld\n", max, min);
    }
    return min;
}

int main() {
    int t;
    ll temp;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &N, &C);
        for(int i = 0; i < N; i++) {
            scanf("%lld", &location[i]);
        }
        sort(location, location + N);
        printf("%lld\n", leastPossibleSpacing());
    }
    return 0;
}



