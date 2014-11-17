// Paste me into the FileEdit configuration dialog
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class BishopMove {
public:
    int howManyMoves( int r1, int c1, int r2, int c2 ) {
        if((r1 + c1) % 2 != (r2 + c2) % 2) return -1;
        if(r1 == r2 && c1 == c2) return 0;
        else if(abs(r1 - r2) == abs(c1 - c2)) return 1;
        return 2;
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
        int r1                    = 4;
        int c1                    = 6;
        int r2                    = 7;
        int c2                    = 3;
        int expected__            = 1;
        std::clock_t start__      = std::clock();
        int received__            = BishopMove().howManyMoves(r1, c1, r2, c2);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
        int r1                    = 2;
        int c1                    = 5;
        int r2                    = 2;
        int c2                    = 5;
        int expected__            = 0;
        std::clock_t start__      = std::clock();
        int received__            = BishopMove().howManyMoves(r1, c1, r2, c2);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
        int r1                    = 1;
        int c1                    = 3;
        int r2                    = 5;
        int c2                    = 5;
        int expected__            = 2;
        std::clock_t start__      = std::clock();
        int received__            = BishopMove().howManyMoves(r1, c1, r2, c2);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
        int r1                    = 4;
        int c1                    = 6;
        int r2                    = 7;
        int c2                    = 4;
        int expected__            = -1;
        std::clock_t start__      = std::clock();
        int received__            = BishopMove().howManyMoves(r1, c1, r2, c2);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    // custom cases
    /*      case 4: {
    			int r1                    = ;
    			int c1                    = ;
    			int r2                    = ;
    			int c2                    = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = BishopMove().howManyMoves(r1, c1, r2, c2);
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 5: {
    			int r1                    = ;
    			int c1                    = ;
    			int r2                    = ;
    			int c2                    = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = BishopMove().howManyMoves(r1, c1, r2, c2);
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 6: {
    			int r1                    = ;
    			int c1                    = ;
    			int r2                    = ;
    			int c2                    = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = BishopMove().howManyMoves(r1, c1, r2, c2);
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
