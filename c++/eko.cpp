//sg
#include<stdio.h>
typedef long long ll;
#define MAX 1000009
ll height[MAX];
ll N, M, maxHeight;
/**
 * This function checks whether the specified height will fetch the 
 * required amount of wood or not
 */
bool isHeightSufficient(ll h) {
    //printf("Check if %lld is sufficient\n", h);
    ll woodCut = 0;
    for(int i = 0; i < N; i++) {
        if(height[i] > h) {
            woodCut += (height[i] - h);
        }
    }
    //printf(" -> %s\n", (woodCut >= M) ? "true" : "false");
    return woodCut >= M;
}

template <class T>
inline void ri(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}
ll minHeightRequired() {
    ll start = 0;
    ll end = maxHeight;
    ll mid = 0;
    while(start < end - 1) {
        mid = (start + end) / 2;
        bool isMidOk = isHeightSufficient(mid);
        if(isMidOk) {
            start = mid;
        } else {
            end = mid;
        }
    }
    return start;
}

int main() {
    scanf("%lld%lld", &N, &M);
    for(int i = 0; i < N; i++) {
        ri(height[i]);
        if(height[i] > maxHeight) {
            maxHeight = height[i];
        }
      //  printf("max = %lld\n", maxHeight);
    }
    printf("%lld\n", minHeightRequired());
    return 0;
}


