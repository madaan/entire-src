//sg
#include<bits/stdc++.h>
using namespace std;
class Date
{
    map<string, int> monNumberMap;
    Date(string day, string mon, string year) {
        monNumberMap = {
            {"jan" , 1},
            {"feb" , 2},
            {"mar" , 3},
            {"apr" , 4},
            {"may" , 5},
            {"jun" , 6},
            {"jul" , 7},
            {"aug" , 8},
            {"sep" , 9},
            {"oct" , 10},
            {"nov" , 11},
            {"dec" , 12}
        };
        month = monNumberMap[mon];
        this->year = year;
        this->day = stoi(day);

    }

    string  year;
    int month;
    int day;
public:
    bool operator < (const Date &d) const {
        if(year < d.year) {
            return 1;
        } else if(month < d.month) {
            return 1;
        } else if(day < d.day) {
            return 1;
        }
        return 0;
    }

    static Date parseDate(string dateStr) {
        stringstream ss(dateStr);
        string day, month, year;
        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year, '/');
        return Date(day, month, year);
    }

    void dump() {
        cout << day << "/" << month << "/" << year << "\n";
    }
};

int main() {
    int n;
    cin >> n;
    string tmp;
    vector<Date> vd;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        vd.push_back(Date::parseDate(tmp));
    }
    sort(vd.begin(), vd.end());
    for(int i = 0; i < n; i++) {
        vd[i].dump();
    }
    return 0;
}
