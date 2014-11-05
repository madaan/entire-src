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

    virtual void heapify_up() = 0;
    virtual void heapify_down() = 0;

    void insert(int x) {
        heap_arr[curr_elems] = x;
        heapify_up();
        curr_elems++;
    }

    int delete_elem() {
        if(curr_elems == 0) {
            return -99999;
        }
        int res = heap_arr[0];
        heap_arr[0] = heap_arr[curr_elems - 1];
        heapify_down();
        curr_elems--;
        return res;
    }

    void dump() {
        for(int i = 0; i < curr_elems; i++) {
            cout << heap_arr[i] << " ";
        }
        cout << "\n";
    }
};

template <typename T>
class MinHeap : public Heap<T> 
{
    public:
    void heapify_up() {
        int i = Heap<T>::curr_elems;
        while(i > 0 && (Heap<T>::heap_arr[Heap<T>::par(i)] > Heap<T>::heap_arr[i])) {
            int parI = Heap<T>::par(i);
            Heap<T>::heap_arr[i] ^= Heap<T>::heap_arr[parI];
            Heap<T>::heap_arr[parI] ^= Heap<T>::heap_arr[i];
            Heap<T>::heap_arr[i] ^= Heap<T>::heap_arr[parI];
            i = parI;
        }
    }

    void heapify_down() {
        int i = 0;
        while() {
            int lc = Heap<T>::lchild(i);
            int rc = Heap<T>::rchild(i);
            T lval = Heap<T>heap_arr[lc];
            T rval = Heap<T>heap_arr[rc];
            if(lval < rval) {
                Heap<T>::heap_arr[i] = lval;
                i = lc;
            } else {
                Heap<T>::heap_arr[i] = rval;
                i = rc;
            }
        }
    }
};



    
int main() {
    MinHeap<int> h;
    for(int i = 10; i > 0; i--) { 
        h.insert(i);
        h.dump();
    }
    h.dump();
    return 0;
}
