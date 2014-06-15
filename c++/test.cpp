//sg
#include <stdio.h>
typedef long long ll;
ll search() {
    int arr[] = {1, 1, 0, 0, 0};
    ll start = 0;
    ll end = sizeof(arr) / sizeof(arr[0]);
    ll mid = 0;
    while(start < end - 1) {
        mid = (start + end) / 2;
        bool isMidOk = (arr[mid] == 1);
        if(isMidOk) {
            start = mid;
        } else {
            end = mid;
        }
    }
    return start;
}


int main()
{
  printf("%lld\n", search());
return 0;
}
