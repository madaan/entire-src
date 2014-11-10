//sg
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100090;
const int MAXK = 10;
typedef long long T;

T cumBIT[MAXK][MAXN+10];
T howMany[MAXK][MAXN+10];
vector<int> values;
vector<int> m;
map<int,int> mapIndex;
void update(int idx, int k, int n, T val)
{
    while(idx<n) {
        cumBIT[k][idx]+=val;
        idx+=(idx&-idx);
    }
}

T getValue(int idx, int k)
{
    T ret = 0;
    while(idx>0) {

        ret+=cumBIT[k][idx];

        idx-=(idx& (-idx));
    }
    return ret;
}
struct myclass {
    bool operator() (int i,int j) {
        return (i<j);
    }
} myobject;
int main()
{

    memset(cumBIT,0,sizeof(cumBIT));
    int n,k = 2, temp1;
    cin>>n;
    values=vector<int>(n,0);
    m = vector<int>(n,0);
    for(int i=0; i<n; i++) {
        cin  >> m[i] >> values[i];
        values[i] = -values[i];
    }
    vector<int> temp = values;

    sort(values.begin(),values.end());
    mapIndex[values[0]]=1;
    for(int i=1; i<n; i++) {
        if(values[i]!=values[i-1]) {
            mapIndex[values[i]]=i+1;
        }
    }

    values=temp;
    T ret = 0;
    for(int i=0; i<n; i++) {
        int index = mapIndex[values[i]];
        howMany[1][i]=1;
        update(index,1,n,howMany[1][i]);
        for(int j=2; j<=k; j++) {
            howMany[j][i]=getValue(index-1,j-1);
            update(index,j,n,howMany[j][i]);
        }
        ret+=howMany[k][i];
    }
    cout<<ret << endl;
    return 0;
}
