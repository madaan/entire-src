//sg
#include<stdio.h>

#include<string.h>

class MaxKeeper {
    char *maxArr;
    int l;
    int presentMax;
    public:
    MaxKeeper(int l) {
        this->l = l;
        presentMax = 0;
        maxArr = new char[l + 1];
    }
    int getNumOnes(char *arr) {
        int res = 0;
        for(int i = 0; i < l; i++) {
            if(arr[i] == '1') {
                res++;
            }
        }
    return res;
    }
    void update(char *arr) {
        int ones = getNumOnes(arr);
        if(ones > presentMax) {
            strcpy(maxArr, arr);
            presentMax = ones;
        }
    }

    char *getMax() {
        return maxArr;
    }
};
MaxKeeper *m;
void dumpBin(char *arr, int i, int l) {
    if(i == l) {
        arr[i] = '\0';
        m->update(arr);
        //printf("%s\n", arr);
        return;
    } 
    arr[i] = '0';
    dumpBin(arr, i + 1, l);
    arr[i] = '1';
    dumpBin(arr, i + 1, l);
}

int main() {
    int l = 30;
    m  = new MaxKeeper(l);
    char * arr = new char[l + 1];
    dumpBin(arr, 0, 20);
    printf("%s\n", m->getMax());
    return 0;
}


