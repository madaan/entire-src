//sg
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> spans;


void getspan(string s, spans &res) {
    int i = 0;
    s += '#';
    int n = s.length();
    for(i = 1; i < n; i++) {
        int sl = 1;
        while(i < n && s[i] == s[i - 1]) {
            sl++;
            i++;
        }
        res.push_back(pi(s[i - 1] - 48, sl));
    }
}

void explode(string s, char on, vector<int> &brksups) {
    stringstream ss(s);
    string item;
    while((getline(ss, item, on))) {
        brksups.push_back(atoi(item.c_str()));
    }
}

string countword(int num) {
if(num == 2) { return "double";}
if(num == 3) { return "triple";}
if(num == 4) { return "quadruple";}
if(num == 5) { return "quintuple";}
if(num == 6) { return "sextuple";}
if(num == 7) { return "septuple";}
if(num == 8) { return "octuple";}
if(num == 9) { return "nonuple";}
if(num == 10) { return "decuple";}
}


void readparts(vector<spans> parts) {
    string numword[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < parts.size(); i++) {
        spans s = parts[i];
        for(int j = 0; j < s.size(); j++) {
            int num = s[j].first;
            int count = s[j].second;
            //cout << num << ":" << count << "\n";
            if(count > 1 && count < 11) {
                cout << countword(count) << " ";
            } else if(count > 10) {
                for(int i = 1; i < count; i++) {
                    cout << numword[num] << " ";
                }
            }
                cout << numword[num] << " ";
        }
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        string number, brkup;
        cin >> number;
        cin >> brkup;
        vector<int> spanlens;
        explode(brkup, '-', spanlens);
        int sumSpan = 0;
        vector<spans> parts;
        for(int i = 0; i < spanlens.size(); i++) {
            int currSpan = spanlens[i];
            spans currSpans;
            getspan(number.substr(sumSpan, currSpan), currSpans);
            parts.push_back(currSpans);
            sumSpan += currSpan;
        }
        readparts(parts);
    }
    return 0;
}
