//sg
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
int N = 1, 
    S = 2,
    E = 3,
    W = 4,
    NE = 5,
    NW = 6,
    SE = 7,
    SW = 8,
    COL = 9;

int getPos(pi b1, pi b2) {
    int x1 = b1.first;
    int y1 = b1.second;
    int x2 = b2.first;
    int y2 = b2.second;
    //cout << x1 << " " << x2 << "\n";
    //cout << y1 << " " << y2 << "\n";
    if(x1 < x2) {
        if(y1 < y2) {
            return NE;
        } else if(y1 > y2) {
            return SE;
        } else {
            return E;
        }
    }
    if(x1 > x2) {
        if(y1 < y2) {
            return NW;
        } else if(y1 > y2) {
            return SW;
        } else {
            return W;
        }
    }
    if(x1 == x2) {
        if(y1 > y2) {
            return S;
        } else if(y2 > y1) {
            return N;
        } else {
            return COL;
        }
    }
    return -1;
}


/*
 * Complete the function below.
*/
bool willCollide(pi b1, char dir1, pi b2, char dir2, int &relPos) {
    relPos = getPos(b1, b2);
    if(relPos == COL) {
        return true;
    } 
    //cout << relPos << "\n";
    if(relPos == NE) {
        if((dir1 == 'N' && dir2 == 'W') || (dir1 == 'E' && dir2 == 'S')) {
            return true;
        } else {
            return false;
        }
    }
    if(relPos == NW) {
        if((dir1 == 'N' && dir2 == 'E') || (dir1 == 'W' && dir2 == 'S')) {
            return true;
        } else {
            return false;
        }
    }
    if(relPos == N) {
        if(dir1 == 'N' && dir2 == 'S') {
            return true;
        } else {
            return false;
        }
    }
    if(relPos == S) {
        if(dir1 == 'S' && dir2 == 'N') {
            return true;
        } else {
            return false;
        }
    }
    if(relPos == SE) {
        if((dir1 == 'S' && dir2 == 'W') || (dir1 == 'E' && dir2 == 'N')) {
            return true;
        } else {
            return false;
        }
    }
    if(relPos == SW) {
        if((dir1 == 'S' && dir2 == 'E') || (dir1 == 'W' && dir2 == 'N')) {
            return true;
        } else {
            return false;
        }
    }
    if(relPos == E) {
        if(dir1 == 'E' && dir2 == 'W') {
            return true;
        } else {
            return false;
        }
    }
    if(relPos == W) {
        if(dir1 == 'W' && dir2 == 'E') {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int remainingBots(vector < int > x, vector < int > y, string direction) {
    int res = 0;
    set<int> collided;
    int x_size = x.size();
    int y_size = y.size();
    vector< pair<pi, char> > bots;
    for(int i = 0; i < x_size; i++) {
        bots.push_back(pair<pi, char>(pi(x[i], y[i]), direction[i]));
    }
    sort(bots.begin(), bots.end());
    for(int i = 0; i < x_size; i++) {
        direction[i] = bots[i].second;
    }
    vector< bool > cld(x_size, false);
                
    for(int i = 0; i < x_size; i++) {
        if(cld[i]) {
            continue;
        }
        for(int j = i + 1; j < y_size; j++) {
            pi b1 = bots[i].first;
            pi b2 = bots[j].first;
            if(cld[j]) {
                continue;
            }
            int relpos;
            if(willCollide(b1, direction[i], b2, direction[j], relpos)) {
                if(relpos != E && relpos != W) {
                    if(!(abs(b1.first - b2.first) == abs(b1.second - b2.second))) {
                        continue;
                    }
                }
                res += 2;
                //cout << i << "and " << j << " collide\n";
                cld[i] = cld[j] = true;
                break;
            }
        }
    }
    return x_size - res;
}
int main() {
    //pi b1(0, 0), b2(10, 10);
    //cout << willCollide(b1, 'N', b2, 'W') << "\n";
    int x[] = {1, 2};
    int y[] = {2, 2};
    char dir[] = {"NW"};
    //int x[] = {-10, 0, 0, 10};
    //int y[] = {0, -10, 10, 0};
    //char dir[] = {"NEWS"};
    cout << remainingBots(vector<int>(x, x + 2), vector<int>(y, y + 2), string(dir)) << "\n";

    return 0;
}
