//sg
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator itr;
itr partition(itr bgn, itr end) {
    itr i = bgn - 1;
    itr j = bgn;
    int pvt = *end;
    for(; j != end; j++) {
        if(*j <= pvt) { //the invariant is that i + 1 to j - 1 are all the elements > pvt
            i++;
            int tmp = *i;
            *i = *j;
            *j = *i;
        }
    }
    i++;
    int tmp = *i;
    *i = pvt;
    *end = tmp;
    return i;
}

//sorts [b_ptr, e_ptr)
void qsort(itr b_ptr, itr e_ptr) {
    if(distance(b_ptr, e_ptr) > 0) {
        cout << "qsort(" << *b_ptr << ", " << *(e_ptr - 1) << ")\n";
        itr pivot = partition(b_ptr, e_ptr - 1);
        qsort(b_ptr, pivot);
        qsort(pivot + 1, e_ptr);
    }
}

int main() {
    int arr[] = {5, 2, 4, 3, 1, 6, 0};
    vector<int> a(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int sz = (sizeof(arr) / sizeof(arr[0]));
    qsort(a.begin(), a.end());
    for(int i = 0; i < sz; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
