//sg
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int getCover(int b, int l, int r) {
    int s = abs(l - r);
    return round(sqrt(b * b + s * s));
}

int main() {
    int l[3], u[3];
    string line[3], temp;

    for(int i = 0; i < 3; i++) {
        cin >> line[i];
        stringstream ss(line[i]);
        getline(ss, temp, ',');
        l[i] = atoi(temp.c_str());
        getline(ss, temp, ',');
        u[i] = atoi(temp.c_str());
    }

    int bl, br, mdiff = 10000000;
    int wl = l[1], wr = l[2], wdiff = 0;
    for(int sl = l[1]; sl <= u[1]; sl++) {
        for(int sr = l[2]; sr <= u[2]; sr++) {
            int diff = abs(sl - sr);
            if(diff < mdiff) {
                mdiff = diff;
                bl = sl;
                br = sr;
            }
            if(diff > wdiff) {
                wdiff = diff;
                wl = sl;
                wr = sr;
            }
        }
    }
    //cout << bl << " " << br << "\n";
    //cout << wl << " " << wr << "\n";
    
    cout << getCover(l[0], bl, br) << "," << getCover(u[0], wl, wr) << "\n";

    return 0;
}

