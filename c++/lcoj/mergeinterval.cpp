//sg
#include<bits/stdc++.h>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    static bool cmp(const Interval &i1, const Interval &i2) {
        return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        for(int i = 0, l = intervals.size(); i < l;) {
            Interval curr = intervals[i];
            int j = i + 1;
            int st = curr.start;
            int en = curr.end;
            while(j < l && intervals[j].start <= en) {
                en = max(en, intervals[j].end);
                j++;
            }
            res.push_back(Interval(st, en));
            i = j;
        }
        return res;
    }
};
int main() {
    return 0;
}
