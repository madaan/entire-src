//All operations in Log(k)
class RBTree
{
    multiset<T> c;
public:
    void insert(T x) {
        c.insert(x);
    }

    void erase(T x) {
        typename multiset<T>::iterator ii = c.find(x);
        if(ii == c.end()) {
            return;
        }
        c.erase(c.find(x));
    }

    void erase(typename multiset<T>::iterator ii) {
        c.erase(ii);
    }

    T del_smallest() {
        T res = *(c.begin());
        erase(c.begin());
        return res;
    }

    T del_largest() {
        typename multiset<T>::iterator ii = c.end();
        ii--;
        T res = *(ii);
        erase(ii);
        return res;
    }

    T get_smallest() {
        T res = *(c.begin());
        return res;
    }

    T get_largest() {
        typename multiset<T>::iterator ii = c.end();
        ii--;
        T res = *(ii);
        return res;
    }

    int size() {
        return c.size();
    }

    void dump() {
        for(auto a : c) {
            cout << a << " ";
        }
        cout << "\n";
    }
};


