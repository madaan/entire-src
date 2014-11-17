//sg
#include<stdio.h>
#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
typedef int ll;
typedef vector<long long int> vll;
long long getMaxArea(int *heights, int numVals) {
    long long currMaxArea = 0;
    ll lastPopped;
    stack<ll> st;
    for(ll i = 0; i < numVals; i++) {
        if(st.empty() || heights[st.top()] <= heights[i]) {
            st.push(i);
        } else {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                lastPopped = st.top();
                st.pop();
                ll numBarBefore = st.empty() ? i : i - st.top() - 1;
                long long area = heights[lastPopped] * numBarBefore;
                if(area > currMaxArea) {
                    currMaxArea = area;
                }
            }
            st.push(i);
        }
    }
    if(!st.empty()) {
        while(!st.empty()) {
            ll lastPopped = st.top();
            st.pop();
            ll numBarBefore = st.empty() ? numVals : numVals - st.top() - 1;
            long long area = heights[lastPopped] * numBarBefore;
            if(area > currMaxArea) {
                currMaxArea = area;
            }
        }
    }
    return currMaxArea;
}
#define pb push_back
#define ini(a, v)   memset(a, v, sizeof(a))
#define max(a, b) (a > b ? a : b)
#define tr(res, i) for(typeof(res.begin()) i = res.begin(); i != res.end(); i++)
int main() {
    int t;
    int M, N;
    int mat[1100][1100];
    char temp[2];
    scanf("%d", &t);
    while(t--) {
        long long res = 0;
        scanf("%d%d", &M, &N);
        for(int i = 0; i <= N; i++) {
            mat[0][i] = 0;
        }
        //memset(mat, 0, sizeof(mat[0][0]) * 1100 * 1100);
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N;) {
                scanf("%s", temp);
                mat[i][j] = (temp[0] == 'F') ? mat[i- 1][j] + 1 : 0;
                j++;
            }
            //vll x;
            //x.assign(mat[i] + 1, mat[i] + N + 1);
            res = max(res, getMaxArea(mat[i] + 1, N) * 3);
        }
        printf("%lld\n", res);
    }
    return 0;
}
