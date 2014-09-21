// Paste me into the FileEdit configuration dialog
#include<bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class TaroGrid {
public:
    int getNumber( vector <string> grid ) {
        char grd[55][55];
        int res[55][55];
        int nr = grid.size();
        int nc = nr;
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                grd[i][j] = grid[i][j];
            }
        }
        for(int j = 0; j < nc; j++) {
            res[0][j] = 1;
            for(int i = 1; i < nr; i++) {
                if(grd[i][j] == grd[i - 1][j]) {
                    res[i][j] = res[i - 1][j] + 1;
                } else {
                    res[i][j] = 1;
                }
            }
        }
        int max = 1;
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(res[i][j] > max) {
                    max = res[i][j];
                }
            }
        }
        return max;
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
        string grid[]             = {"W"};
        int expected__            = 1;

        std::clock_t start__      = std::clock();
        int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
        string grid[]             = {"WB",
                                     "BW"
                                    };
        int expected__            = 1;

        std::clock_t start__      = std::clock();
        int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
        string grid[]             = {"BWW",
                                     "BBB",
                                     "BWB"
                                    };
        int expected__            = 3;

        std::clock_t start__      = std::clock();
        int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
        string grid[]             = {"BWBW",
                                     "BBWB",
                                     "WWWB",
                                     "BWWW"
                                    };
        int expected__            = 3;

        std::clock_t start__      = std::clock();
        int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 4: {
        string grid[]             = {"BWB",
                                     "BBW",
                                     "BWB"
                                    };
        int expected__            = 3;

        std::clock_t start__      = std::clock();
        int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 5: {
        string grid[]             = {"BBWWBBWW",
                                     "BBWWBBWW",
                                     "WWBBWWBB",
                                     "WWBBWWBB",
                                     "BBWWBBWW",
                                     "BBWWBBWW",
                                     "WWBBWWBB",
                                     "WWBBWWBB"
                                    };
        int expected__            = 2;

        std::clock_t start__      = std::clock();
        int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }

    // custom cases

    /*      case 6: {
    			string grid[]             = ;
    			int expected__            = ;

    			std::clock_t start__      = std::clock();
    			int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 7: {
    			string grid[]             = ;
    			int expected__            = ;

    			std::clock_t start__      = std::clock();
    			int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 8: {
    			string grid[]             = ;
    			int expected__            = ;

    			std::clock_t start__      = std::clock();
    			int received__            = TaroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
