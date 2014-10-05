//sg
#include<bits/stdc++.h>
using namespace std;
typedef unsigned int TX;

struct DataItem {
    TX xlock;
    set<TX> slock;
    public:
    DataItem() {
        xlock = -1;
    }
};

    const string ignor = "IGNORED";
    const string granted = "GRANTED";
    const string denied = "DENIED";
    const int MAX = 10009;
class TXHandler {
    map<int, DataItem> items;
    set<TX> ignored;

    public:
    string process(char lock, TX tx, int data_id) {
        if(items.find(data_id) == items.end()) { //first time for this data item, can do anything
            items[data_id] =  DataItem();
        }
        if(ignored.find(tx) != ignored.end()) {
            return ignor;
        } 
        //someone else got the x lock, can't do anything, have to ignore
        if(items[data_id].xlock != -1 && items[data_id].xlock != tx) {
            ignored.insert(tx);
            return denied;
        }
        if(lock == 'S') { //can give shared lock
            items[data_id].slock.insert(tx);
            return granted;
        } else if(lock == 'X') {
            if(items[data_id].slock.size() > 1 || (items[data_id].slock.size() == 1 && *(items[data_id].slock.begin()) != tx)) {
            ignored.insert(tx);
            return denied;
            } else {
                items[data_id].xlock = tx;
                return granted;
            }
        }
        return ignor;
    }
};

int main() {
    char type;
    TX tx;
    TXHandler handler;
    int data_id;
    while(true) {
        cin >> type >> tx >> data_id;
        if(type == '#') {
            return 0;
        }
        cout << handler.process(type, tx, data_id) << "\n";
        
    }
    return 0;
}

