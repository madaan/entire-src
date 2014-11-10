// Paste me into the FileEdit configuration dialog
#include <string>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
class Egalitarianism3Easy {
    int adj[20][20];
    int d[12][12];
    int dist[20][20];
    vector<pi> pairs[10];
public:
    int allPair(int n) {
        if(n == 1) {
            return 1;
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(i == j) continue;
                    if (adj[i][k] + adj[k][j] < adj[i][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
        int np, mp;
        mp = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                np = 2;
                int cdist = adj[i][j];
                printf("Testing (%d, %d)\n", i, j);
                for(int k = j + 1; k <= n; k++) {
                    if(adj[i][k] == cdist && adj[j][k] == cdist) {
                        np++;
                    }
                }
                if(np > mp) {
                    mp = np;
                }
            }
        }
        return mp;
    }
    int collectPair(int n) {
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                pairs[adj[i][j]].push_back(pi(i, j));
            }
        }
        for(int i = 1; i <= n; i++) {
            sort(pairs[i].begin(), pairs[i].end());
        }
    }
    int maxCities( int n, vector <int> a, vector <int> b, vector <int> len ) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                adj[i][j] = 100;
            }
        }

        for(int i = 0; i < n - 1; i++) {
            adj[a[i]][b[i]] = len[i];
            adj[b[i]][a[i]] = len[i];
        }
        return allPair(n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                printf("%d ", adj[i][j]);
            }
            printf("\n");
        }
    }
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
using std::string;
using std::vector;
int run_test_case(int);
void run_test(int casenum = -1, bool quiet = false) {
    if (casenum != -1) {
        if (run_test_case(casenum) == -1 && !quiet) {
            std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
        }
        return;
    }
    int correct = 0, total = 0;
    for (int i=0;; ++i) {
        int x = run_test_case(i);
        if (x == -1) {
            if (i >= 100) break;
            continue;
        }
        correct += x;
        ++total;
    }
    if (total == 0) {
        std::cerr << "No test cases run." << std::endl;
    } else if (correct < total) {
        std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
    } else {
        std::cerr << "All " << total << " tests passed!" << std::endl;
    }
}
int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
    std::cerr << "Example " << casenum << "... ";
    string verdict;
    vector<string> info;
    char buf[100];
    if (elapsed > CLOCKS_PER_SEC / 200) {
        std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
        info.push_back(buf);
    }
    if (expected == received) {
        verdict = "PASSED";
    } else {
        verdict = "FAILED";
    }
    std::cerr << verdict;
    if (!info.empty()) {
        std::cerr << " (";
        for (size_t i=0; i<info.size(); ++i) {
            if (i > 0) std::cerr << ", ";
            std::cerr << info[i];
        }
        std::cerr << ")";
    }
    std::cerr << std::endl;
    if (verdict == "FAILED") {
        std::cerr << "    Expected: " << expected << std::endl;
        std::cerr << "    Received: " << received << std::endl;
    }
    return verdict == "PASSED";
}
int run_test_case(int casenum__) {
    switch (casenum__) {
    case 0: {
        int n                     = 4;
        int a[]                   = {1,1,1};
        int b[]                   = {2,3,4};
        int len[]                 = {1,1,1};
        int expected__            = 3;
        std::clock_t start__      = std::clock();
        int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
        int n                     = 6;
        int a[]                   = {1,2,3,2,3};
        int b[]                   = {2,3,4,5,6};
        int len[]                 = {2,1,3,2,3};
        int expected__            = 3;
        std::clock_t start__      = std::clock();
        int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
        int n                     = 10;
        int a[]                   = {1,1,1,1,1,1,1,1,1};
        int b[]                   = {2,3,4,5,6,7,8,9,10};
        int len[]                 = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
        int expected__            = 9;
        std::clock_t start__      = std::clock();
        int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
        int n                     = 2;
        int a[]                   = {1};
        int b[]                   = {2};
        int len[]                 = {3};
        int expected__            = 2;
        std::clock_t start__      = std::clock();
        int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 4: {
        int n                     = 1;
        int a[]                   = {};
        int b[]                   = {};
        int len[]                 = {};
        int expected__            = 1;
        std::clock_t start__      = std::clock();
        int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    // custom cases
    /*      case 5: {
    			int n                     = ;
    			int a[]                   = ;
    			int b[]                   = ;
    			int len[]                 = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 6: {
    			int n                     = ;
    			int a[]                   = ;
    			int b[]                   = ;
    			int len[]                 = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 7: {
    			int n                     = ;
    			int a[]                   = ;
    			int b[]                   = ;
    			int len[]                 = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = Egalitarianism3Easy().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    default:
        return -1;
    }
}
}
#include <cstdlib>
int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(std::atoi(argv[i]));
    }
}
// END CUT HERE
