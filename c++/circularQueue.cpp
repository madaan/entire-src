//sg
#include<cstdio>
template <class T>
class CircularQueue {
static int MAX;
    T buff[10];
    public:
    int in, out, n;
    CircularQueue(int n) {
        this -> n = 0;
        in = out = 0;
    }
    T getNext() {
        if(in == out) {
            printf("Buffer empty\n");
            return -1;
        }
        T res = buff[out];
        out = (out + 1) % n;
        return res;
    }

    void insert(T ele) {
        if((in + 1) % n == out) {
            printf("Buffer full\n");
            return;
        }
        buff[in] = ele;
        in = (in + 1) % n;
    }
};
template <class T>
int CircularQueue<T>::MAX = 10;
int main() {
    CircularQueue<int> c(5);
    return 0;
}

