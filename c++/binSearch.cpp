//sg
//Binary search is actually quite hard to get right the first time
#include<cstdlib>
#include<cstdio>
int arr[100];
int nearestBinSearch(int l, int r, int x) {
    int mid, lprev;
    lprev = l;
    while(l < r) {
        mid = l + ((r - l + 1) / 2);
        printf("(%d - %d), mid = %d\n", l, r, mid);
        if(arr[mid] <= x) { //this is legal
            l = mid;
        } else {
            r = mid - 1;
        }

    }
    return l;
}

int main(int argc, char *argv[]) {
    for(int i = 0; i < 10; i++) {
        arr[i] = i * 3;
        printf("%3d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < 10; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    int index = nearestBinSearch(1, 9, atoi(argv[1]));
    printf("arr[%d] = %d\n", index, arr[index]);

    return 0;
}
