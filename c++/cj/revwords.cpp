//sg
#include<bits/stdc++.h>
using namespace std;
void process(string temp) {
    stringstream ss(temp);
    string part;
    stack<string> parts;
    while(getline(ss, part, ' ')) {
        parts.push(part);
    }
    while(parts.size() > 1) {
        cout << parts.top() << " ";
        parts.pop();
    }
    cout << parts.top() << "\n";
}


int main() {
    int t;
    cin >> t;
    cin.ignore();
    for(int qq = 1; qq <= t; qq++) {
        printf("Case #%d: ", qq);
        string ip;
        getline(cin, ip);
        //cout << ip << "\n";
        process(ip);
    }
    return 0;
}
