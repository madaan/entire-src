//sg
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
    int N;
    int CAP;
    map<int, int> cache;
public:
    /* This data structure abstracts out the LRU maintenance of the queue
     */
    class MyLRUQueue {
        map<int, int> posMap; //keeps track of where an element is in the queue
        int front, back;
        vector<int> keys; //to allow fast random deletions
    public:
        MyLRUQueue() {
            front = 0;
            back = 1;
            keys.push_back(-2);
        }
        void updateLRU(int x) {
            map<int, int>::iterator i = posMap.find(x);
            if(i != posMap.end()) {
                int prevIndex = (*i).second;
                //cout << "Invalidating : at " << prevIndex << " val : " << keys[prevIndex] << "\n";
                keys[prevIndex] = -2;
            }
            posMap[x] = back;
            keys.push_back(x);
            back++;
        }
        //returns the least recently used key and deletes is too
        int getLRU() {
            if(front == back) {
                return -1;
            }
            while(front <= back && keys[front + 1] == -2) {
                front++;
            }
            front++;
            return keys[front];
        }
    };
    MyLRUQueue lrqueue;
    LRUCache(int capacity) {
        CAP = capacity;
        N = 0; //number of element already present
    }
    int get(int key) {
        map<int, int>::iterator i = cache.find(key);
        if(i == cache.end()) {
            return -1;
        }
        lrqueue.updateLRU(key);
        return (*i).second == -2 ? -1 : (*i).second;
    }
    void set(int key, int value) {
        if(get(key) != -1 && get(key) != -2) { //already present
            cache[key] = value;
            lrqueue.updateLRU(key);
            return;
        }
        assert(CAP + 1 > N);
        //need to insert
        if(N < CAP) {
            cache[key] = value;
            N++;
        } else {
            //cout << "Elements : " << N << " Capacity : " << CAP << "\n";
            int lruElement = lrqueue.getLRU();
            if(lruElement == -1) return;
            cache[lruElement] = -2; //invalidate
            cache[key] = value;
            //cout << "replacing : " << lruElement << "\n";
        }
        lrqueue.updateLRU(key);
    }
};
int main() {
    LRUCache lc(2);
    //cout << "set(2, 1)\n";
    lc.set(2, 1);
    //cout << "set(1, 1)\n";
    lc.set(1, 1);
    //cout << "get(2)\n";
    cout << "--> " << lc.get(2) << "\n";
    //cout << "set(4, 1)\n";
    lc.set(4, 1);
    //cout << "get(1)\n";
    cout << "--> " << lc.get(1) << "\n";
    //cout << "get(2)\n";
    cout << "--> " << lc.get(2) << "\n";
    return 0;
}
