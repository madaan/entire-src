//sg
#include<bits/stdc++.h>
using namespace std;

bool is_not_digit(char c)
{
    return !std::isdigit(c);
}

bool numeric_string_compare(const std::string& s1, const std::string& s2)
{
    // handle empty strings...

    std::string::const_iterator it1 = s1.begin(), it2 = s2.begin();

    if (std::isdigit(s1[0]) && std::isdigit(s2[0])) {
        int n1, n2;
        std::stringstream ss(s1);
        ss >> n1;
        ss.clear();
        ss.str(s2);
        ss >> n2;

        if (n1 != n2) return n1 < n2;

        it1 = std::find_if(s1.begin(), s1.end(), is_not_digit);
        it2 = std::find_if(s2.begin(), s2.end(), is_not_digit);
    }

    return std::lexicographical_compare(it1, s1.end(), it2, s2.end());
}

char getDig(char c) {
    switch(c) {
        case 'a':
        case 'b':
        case 'c':
            return '2';
        case 'd':
        case 'e':
        case 'f':
            return '3';
        case 'g':
        case 'h':
        case 'i':
            return '4';
        case 'j':
        case 'k':
        case 'l':
            return '5';
        case 'm':
        case 'n':
        case 'o':
            return '6';
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return '7';
        case 't':
        case 'u':
        case 'v':
            return '8';
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return '9';
    }
}

string stringToDig(string s) {
    string dig = "";
    for(long long i = 0, l = s.length(); i < l; i++) {
        dig += string(1, getDig(s[i]));
    }
    return dig;
}


int main() {
    long long n;
    cin >> n;
    string tmp;
    map<string, vector<string>> mp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        string num = stringToDig(tmp);
        mp[num].push_back(tmp);
    }
    vector<string> keySet;
    for(auto i : mp) {
        keySet.push_back(i.first);
    }
    sort(keySet.begin(), keySet.end(), numeric_string_compare);

    for(int i = 0, l = keySet.size(); i < l; i++) {
        vector<string> sts = mp[keySet[i]];
        sort(sts.begin(), sts.end());
        
        for(auto j : sts) {
            cout << keySet[i] << " " << j << "\n";
        }
    }
    return 0;
}
