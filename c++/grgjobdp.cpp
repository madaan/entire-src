//sg
#include<bits/stdc++.h>
using namespace std;

//typedefs
typedef unsigned long long ll;
typedef pair<ll, pair<int, int> > span;
typedef pair<int, int> pi;
vector<span> spans;
int numSpans;
int n, m, k;
#define max 5009
ll dp[max][max];

bool comp(span a, span b) {
    if(a.first == b.first) {
        return a.second.second > b.second.second;
    }
    return a.first > b.first;
}

bool ok(pi x, pi y) {
    pi a, b;
    if(x.first < y.first) {
        a = x;
        b = y;
    } else if(y.first < x.first) {
        a = y;
        b = x;
    } else {
        return false;
    }
    if(!(a.second < b.first)) {
        return false;
    }
    return true;
}

//returns the next compatible span
int nxt(int i) {
    for(int j = i + 1; j < numSpans; j++) {
        if(ok(spans[i].second, spans[j].second)) {
            return j;
        }
    }
    return numSpans;
}


ll getm(int i, int picked) {
    cout << "getm( " << i << ", " << picked << ")\n";
    if(dp[i][picked] != -1) return dp[i][picked];
    if((picked == k) || (i == numSpans)){ 
        return dp[i][picked] = 0;
    }
    int ni = nxt(i);
    ll a = dp[ni][picked + 1] = getm(ni, picked  + 1);
    ll b = dp[i + 1][picked] = getm(i + 1, picked);
    a += spans[i].first;
    return (dp[i][picked] = a > b ? a : b);
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    ll arr[5009];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= n - m + 1; i++) {
        ll sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i + j];
        }
        spans.push_back(span(sum, pi(i, i + m - 1)));
    }
    numSpans = spans.size();
    sort(spans.begin(), spans.end(), comp);
    for(int i = 0; i < spans.size(); i++) {
        printf("%lld : %d - %d\n", spans[i].first, (spans[i].second).first, spans[i].second.second);
    }
    cout << getm(0, 0) << "\n";
    return 0;
}
