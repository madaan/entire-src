//sg
#include<stdio.h>
#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef vector<long long int> vll;
long long getMaxArea(vll heights) {
    ll numVals = heights.size();
    ll currMaxArea = 0;
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
                ll area = heights[lastPopped] * numBarBefore;
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
            ll area = heights[lastPopped] * numBarBefore;
            if(area > currMaxArea) {
                currMaxArea = area;
            }
        }
    }
    return currMaxArea;
}

#define pb push_back
int main() {
    //ll arr[] = {3, 2, 3};
    //ll arr[] = {6, 2, 5, 4, 5, 1, 6};

    ll arr[100010];

    while(true) {
        int nums;
        scanf("%d", &nums);
        if(nums == 0) {
            return 0;
        }
        vll x;
        ll temp;
        while(nums--) {
            scanf("%lld", &temp);
            x.pb(temp);
        }
        printf("%lld\n", getMaxArea(x));
    }
    return 0;
}
