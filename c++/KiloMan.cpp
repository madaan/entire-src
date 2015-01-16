//sg
#include <string>
#include <vector>
using namespace std;
#define tr(v, i) for(auto i = v.begin(); i != v.end(); i++)
class KiloMan {
public:
    int hitsTaken(vector <int> pattern, string jumps) {
        int hits = 0;
        for(int i = 0; i < pattern.size(); i++) {
            if(jumps[i] == 'S') {
                if(pattern[i] <= 2) {
                    hits++;
                }
            } else if(pattern[i] > 2) {
                hits++;
            }
        }
        return hits;
    }
};
// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
