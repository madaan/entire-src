//sg
//a simple heap representation
#include<bits/stdc++.h>
using namespace std;
//The type must implement >=, >, <=, <
template <class T>
class Heap
{
    protected:
        enum { MAX = 1000};
        T heap_arr[MAX];
        int curr_elems;
    public:
    int par(int i) {
        return ((i - 1) / 2);
    }
    int lchild(int i) {
        return heap_arr[2 * i + 1];
    }
    int rchild(int i) {
        return heap_arr[2 * i + 2];
    }
    void insert(int x) {
        heap_arr[curr_elems] = x;
        heapify();
        curr_elems++;
    }
    void dump() {
        for(int i = 0; i < curr_elems; i++) {
            cout << heap_arr[i] << " ";
        }
        cout << "\n";
    }
    virtual void heapify();
};

template <class T>
class MinHeap : public Heap<T> 
{
    public:
    void heapify() {
        int i = curr_elems;
        while(i >= 0 && (heap_arr[par(i)] > heap_arr[i])) {
            int parI = par(i);
            heap_arr[i] ^= heap_arr[parI];
            heap_arr[parI] ^= heap_arr[i];
            heap_arr[i] ^= heap_arr[parI];
            i = parI;
        }
    }
};



    
int main() {
    return 0;
}
