//sg
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<long long> vll;
#define pb push_back
#define all(x) (x.begin(), x.end())
int main() {
    int t;
    int N, C;
    scanf("%d", &t);
    
    while(t--) {
        vll nums(0);
        scanf("%d%d", &N, &C);
        
        for(int i = 0; i < N; i++) {
            scanf("%lld", &temp);
            nums.pb(temp);
        }
        sort(all(nums));
        int l = nums.size();
        ll curr_win_size = nums[l - 1] - nums[0];
        ll min_win_size = curr_win_size;







