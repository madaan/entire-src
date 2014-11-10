// Paste me into the FileEdit configuration dialog
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class GameOfStones {
public:
    bool isint(double x) {
        return (floor(x) == x);
    }
    int count( vector <int> stones ) {
        int mine = *(min(stones.begin(), stones.end()));
        vector< int> diff(stones.size());
        bool iseven = false, isodd = false;
        int sum = 0;
        for(int i = 0; i < stones.size(); i++) {
            diff[i] = stones[i] - mine;
            if(diff[i] % 2 == 0) {
                iseven = true;
            } else {
                isodd = true;
            }
            sum += diff[i];
        }
        if(!(isodd ^ iseven)) {
            return -1;
        }
        int res = 0;
        double avg = double(sum) / stones.size();
        sum = avg;
        if(sum % 2 != 0 || !isint(avg)) {
            return -1;
        }
        for(int i = 0, l = stones.size(); i < l; i++) {
            if(diff[i] < sum) {
                res += ((sum - diff[i]) / 2);
            }
        }
        return res;

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
        int stones[]              = {7, 15, 9, 5};
        int expected__            = 3;
        std::clock_t start__      = std::clock();
        int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
        int stones[]              = {10, 16};
        int expected__            = -1;
        std::clock_t start__      = std::clock();
        int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
        int stones[]              = {2, 8, 4};
        int expected__            = -1;
        std::clock_t start__      = std::clock();
        int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
        int stones[]              = {17};
        int expected__            = 0;
        std::clock_t start__      = std::clock();
        int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 4: {
        int stones[]              = {10, 15, 20, 12, 1, 20};
        int expected__            = -1;
        std::clock_t start__      = std::clock();
        int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    // custom cases
    /*      case 5: {
    			int stones[]              = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 6: {
    			int stones[]              = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 7: {
    			int stones[]              = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = GameOfStones().count(vector <int>(stones, stones + (sizeof stones / sizeof stones[0])));
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
