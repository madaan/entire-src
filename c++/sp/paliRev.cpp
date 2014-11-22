//sg
#include<bits/stdc++.h>
using namespace std;
int high_bit(int x) {
    int mask = 1;
    int hb = -1;
    for(int i = 0; i < 32; i++) {
        if((mask << i) & x) {
            hb = i;
        }
    }
    return hb;
}
bool isPali(int ip) {
    int hb = high_bit(ip);
    if(hb == -1) {
        return true;
    }
    int lmask = 1 << hb;
    int rmask = 1;
    for(int i = 0; i < hb / 2; i++) {
        bool lbit_set = ip & lmask;
        bool rbit_set = ip & rmask;
        if(lbit_set ^ rbit_set) {
            return false;
        }
        lmask = lmask >> 1;
        rmask = rmask << 1;
    }
    return true;
}

int countBits(int ip) {
    int res = 0;
    while(ip) {
        if(ip & 1) {
            res++;
        }
        ip = ip >> 1;
    }
    return res;
}
int main(int argc, char *argv[]) {
    int ip = atoi(argv[1]);
    printf("%d\n", isPali(ip) ? countBits(ip) : -1);
    return 0;
}
