//sg
#include<bits/stdc++.h>
using namespace std;

/*
 *An wrapper over the multiset
 */
template <typename T>
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

int main(int argc, char *argv[1]) {
    RBTree<double> l_tree, r_tree;
    int k;
    cin >> k;
    double P;
    cin >> P;
    deque<double> cq(k);
    int lmax = (k + 1) / 2;
    int rmax = k / 2;
    double val, median;
    bool hasStarted = false;
    int added_elements = 0;
    setiosflags(ios::fixed);
    while(cin >> val) {
        //cout << "===\n";
        //cout << "Ltree : " << l_tree.size() << "\n";
        //l_tree.dump();
        //cout << "Rtree : " << r_tree.size() << "\n";
        //r_tree.dump();

        //cout << "Read : " << val << "\n";
        if(hasStarted) {
            //cout << "med : " << median << " val : " << val << "\n";
            if((abs(median - val)  / median) > P) {
                cout << fixed << setprecision(3) << val << "\n";
            }
        }
        cq.push_back(val);
        if(l_tree.size() > 0 && l_tree.get_largest() <= val) {
            r_tree.insert(val);
        } else {
            l_tree.insert(val);
        }
        added_elements++;
        //balance if needed
        if(added_elements >= k) {
            while(l_tree.size() > lmax) {
                //cout << "l";
                r_tree.insert(l_tree.del_largest());
            }
            while(r_tree.size() > rmax) {
                //cout << "r";
                l_tree.insert(r_tree.del_smallest());
            }
            if(k % 2) {
                median = l_tree.get_largest();
            } else {
              //  median = r_tree.get_smallest();
               median = (l_tree.get_largest() + r_tree.get_smallest()) / 2;
            }
            double rem = cq.front();
            cq.pop_front();
            if(l_tree.get_largest() < rem) {
                r_tree.erase(rem);
            } else {
                l_tree.erase(rem);
            }
            //printf("%.3f\n", median);
            //cout << "median : " << showpoint << setprecision(4) << median << "\n";
            hasStarted = true;
        }
    }
    return 0;
}
