//sg
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    double slope(Point a, Point b) {
        if(a.y == b.y) {
            return 0;
        } else if(a.x == b.x) {
            return -10000000;
        } else {
            return static_cast<double>(b.y - a.y) / (b.x - a.x);
        }
    }
    bool isSame(Point a, Point b) {
        return (a.x == b.x && a.y == b.y);
    }
    //returns the maximum number of points in line with i
    int countPoints(int i, vector<Point> &points) {
        map<double, int> slopeCountMap; //keeps track of the number of points that are at a given absolute slope from the ith point
        Point fixed_p = points[i];
        int ans = 0;
        int samep = 0;
        for(int j = 0, pl = points.size(); j < pl; j++) {
            if(i == j) continue;
            Point curr_p = points[j];
            if(isSame(curr_p, fixed_p)) {
                samep++;
                continue;
            }
            double slp = slope(fixed_p, curr_p);
            //cout << "Slope between (" << curr_p.x << ", " << curr_p.y << ") <> (" << fixed_p.x << ", " << fixed_p.y << ") = " << slp << "\n";
            if(slopeCountMap.find(slp) == slopeCountMap.end()) {
                slopeCountMap[slp] = 1;
            } else {
                slopeCountMap[slp]++;
            }
            ans = max(ans, slopeCountMap[slp]);
        }
        return ans + samep + 1;
    }
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        int pl = points.size();
        if(pl == 1) {
            return 1;
        }
        for(int i = 0; i < pl; i++) {
            ans = max(ans, countPoints(i, points));
        }
        return ans;
    }
};
int main() {
    Point p(0, 0);
    vector<Point> points;
    points.push_back(Point(84,250));
    points.push_back(Point(0,0));
    points.push_back(Point(1,0));
    points.push_back(Point(0,-70));
    points.push_back(Point(0,-70));
    points.push_back(Point(1,-1));
    points.push_back(Point(21,10));
    points.push_back(Point(42,90));
    points.push_back(Point(-42,-230));
    //points.push_back(p);
    Solution s;
    cout << s.maxPoints(points) << "\n";
    return 0;
}
