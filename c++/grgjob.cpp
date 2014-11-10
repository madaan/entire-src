//sg
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, pair<int, int> > span;
typedef pair<int, int> pi;
bool comp(span a, span b) {
    if(a.first == b.first) {
        return a.second.second > b.second.second;
    }
    return a.first > b.first;
}
vector<pi> taken;
list<pi> rngs;
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
bool iscmpt(span x) {
    pi crds = x.second;
    int l = taken.size();
    for(int i = 0; i < l; i++) {
        if(!ok(taken[i], crds)) {
            return false;
        }
    }
    return true;
}
int rem(pi x) {
    int res = 0;
    for(list<pi>::iterator i = rngs.begin(); i != rngs.end(); i++) {
        if(ok(x, *i)) {
            res++;
        }
    }
    return res;
}
void clear(pi x) {
    list<pi>::iterator i = rngs.begin();
    while (i != rngs.end())
    {
        if(!ok(x, *i))
        {
            rngs.erase(i++);  // alternatively, i = items.erase(i);
        }
        else
        {
            ++i;
        }
    }
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    ll arr[5009];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<span> spans;
    for(int i = 1; i <= n - m + 1; i++) {
        ll sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i + j];
        }
        spans.push_back(span(sum, pi(i, i + m - 1)));
        rngs.push_back(pi(i, i + m - 1));
    }
    sort(spans.begin(), spans.end(), comp);
    for(int i = 0; i < spans.size(); i++) {
        printf("%lld : %d - %d\n", spans[i].first, (spans[i].second).first, spans[i].second.second);
    }
    ll res = 0;
    int numSpans = spans.size();
    int picked = 0;
    for(int i = 0; i < numSpans && picked < k; i++) { //pick k non conflicting spans
        //cout << iscmpt(spans[i]) << "\n";
        if(iscmpt(spans[i]) && (rem(spans[i].second) >= (k - picked - 1))) {
            //printf("picking %lld -> %d - %d\n", spans[i].first, spans[i].second.first, spans[i].second.second);
            taken.push_back(spans[i].second);
            clear(spans[i].second);
            res += spans[i].first;
            picked++;
        }
    }
    //cout << picked << "\n";
    cout << res << "\n";
    return 0;
}
