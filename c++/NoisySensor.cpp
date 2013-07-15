//sg
#include <vector>
#include <stdio.h>
using namespace std;
class NoisySensor
{
    public :
        vector<int> medianFilter(vector<int> data)
        {
            int x;
            vector<int> res;
            if(data.size() < 2) {
                return data;
            }
            res.push_back(data[0]);
            for(std::vector<int>::size_type i = 1; i != data.size() - 1; i++) {
                res.push_back(x = getMedian(data[i - 1], data[i], data[i + 1]));
           }
            res.push_back(data[data.size() - 1]);
            return res;
        }

    private:
        int getMedian(int a1, int b, int c) {
            int a[3];
            a[0] = a1;
            a[1] = b;
            a[2] = c;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2 - i; j++) {
                    if(a[j] > a[j + 1]) { 
                        a[j] ^= a[j + 1];
                        a[j + 1] ^= a[j];
                        a[j] ^= a[j + 1];
                    }
                }
            }
            return a[1];
        }
};

        int getMedian(int a1, int b, int c) {
            int a[3];
            a[0] = a1;
            a[1] = b;
            a[2] = c;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2 - i; j++) {
                    if(a[j] > a[j + 1]) { 
                        a[j] ^= a[j + 1];
                        a[j + 1] ^= a[j];
                        a[j] ^= a[j + 1];
                    }
                }
            }
            return a[1];
        }


int main()
{
    int arr[] = {432296535, 1983848899, -434724194, 135703525, -1146336142,
-680568092, -1183352724, 1337550909, -1597342716, -1901441857,
1726722019, -558651015, 649930787, 1889036519, 1752815826,
930647381, -852547667, 2028345278, -1835531493, -1040566300,
-1566043783, -1282411107, -1123988603, 2132078516, -1169614369,
-523503536, 1466102514, -2003903121, -779001645, 1919742042,
1210980485, -9273881, 1033032137, -1474003783, 296280591,
920184999, -1235054743, -1329769514, -1727085135};
    vector<int> data(arr, arr + (sizeof(arr) / sizeof(int)));
    NoisySensor ns;
    vector<int> res = ns.medianFilter(data);
    for(vector<int>::iterator st = res.begin(); st != res.end(); st++) {
        printf("%d ", *st);
    }
    printf("\n");
    printf("%d\n", getMedian(-434724194, 135703525, -1146336142));
    return 0;
}



