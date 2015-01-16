//sg
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
// Basic macros
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())
#define INF 2000000009
const double eps = 1e-9;
class CLEANTAB {
    int m, n;
    int MAX_N, MAX_C;
    list<int> refTimes[404];
    set<int> frame;
    set<int> customers;
    vector<int> refString;
    int ts;
public:
    CLEANTAB(int n, int m) {
        MAX_C = 404;
        MAX_N = 202;
        this->m = m;
        this->n = n;
        ts = 0;
    }
    int start() {
        readRefString();
        eatTillFault();
        if(m < n) {
            //less customers than fault
            return customers.size();
        }
        if(ts == m) { // no need to do page swapping
            return customers.size();
        }
        //start the simulation
        int pageFaults = 0;
        for(; ts < m; ts++) {
            updatePages();
            int currCust = refString[ts];
            /*
            printf("Time : %d Frame : ", ts);
            tr(frame, i) {
                printf("%d ", *i);
            }
            printf("\n");
            */
            if(frame.find(currCust) == frame.end()) { //need to swap
                //printf("Fault for %d\n", currCust);
                pageFaults++;
                int maxTC, maxTV;
                getBestPageSlow(maxTC, maxTV);
                //getBestPageToDel(maxTC, maxTV);
                //printf("Replacing %d with %d\n", maxTC, currCust);
                frame.erase(maxTC);
                frame.insert(currCust);
            }
        }
        return pageFaults + n; //count intial too
    }
    //returns the customer who will not order for the longest period of time
    void getBestPageToDel(int &maxTC, int &maxTV) {
        maxTV = 0;
        tr(frame, i) {
            if(refTimes[*i].front() > maxTV) {
                maxTC = *i;
                maxTV = refTimes[*i].front();
            }
        }
    }
    void getBestPageSlow(int &cust, int &val) {
        vector<int>::iterator it, maxIt;
        tr(frame, i) {
            it = find(refString.begin() + ts, refString.end(), *i);
            if(it == refString.end()) {
                cust = *i;
                return;
            }
            if(it > maxIt) {
                maxIt = it;
                cust = *i;
            }
        }
    }
    void updatePages() {
        tr(customers, i) {
            if(refTimes[*i].front() < ts) {
                refTimes[*i].pop_front();
                if(refTimes[*i].empty()) {
                    refTimes[*i].push_front(INF);
                }
            }
        }
    }
    void readRefString() {
        int temp;
        for(int i = 0; i < m; i++) {
            scanf("%d", &temp);
            customers.insert(temp);
            refString.push_back(temp);
            refTimes[temp].push_back(i);
        }
    }
    //eats the reference string till there is a page fault
    void eatTillFault() {
        ts = 0;
        while(ts < m && frame.size() < n) { //set size is O(1)
            frame.insert(refString[ts++]);
        }
    }
};
int main() {
    int t;
    scanf("%d", &t);
    int n, m;
    while(t--) {
        scanf("%d%d", &n, &m);
        CLEANTAB ct(n, m);
        printf("%d\n", ct.start());
    }
    return 0;
}
