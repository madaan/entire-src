// Paste me into the FileEdit configuration dialog
#include <bits/stdc++.h>
using namespace std;
class PotentialGeometricSequence {
public:
    int numberOfSubsequences( vector <int> d ) {
        int l = d.size();
        int diff = d[1] - d[0];
        int i = 2;
        vector<int> lens;
        int st = 0;
        bool in1 = false;
        while(i < l) {
            printf("here");
            in1 = false;
            int ip  = i;
            while(i < l && (d[i] - d[i - 1] == diff)) {
                i++;
                printf("i = %d\n", i);
                in1 = true;
            }
            printf("i = %d adding %d\n", i, i - st);
            lens.push_back(i - st);
            st = i - 1;
            diff = d[i] - d[i - 1];
            if(i == ip) {
                printf("here!");
            }
            printf("here <>, i = %d, l = %d", i, l);
        }
        int res = 0;
        for(vector<int>::iterator i = lens.begin(); i != lens.end(); i++) {
            int val = *i;
            res += ((val * (val - 1)) / 2);
        }
        printf("\n");
        res += l;
        if(l == 2) res++;
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
        int d[]                   = {6, 6};
        int expected__            = 3;
        std::clock_t start__      = std::clock();
        int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
        int d[]                   = {1,2,4};
        int expected__            = 5;
        std::clock_t start__      = std::clock();
        int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
        int d[]                   = {3,2,1,0};
        int expected__            = 10;
        std::clock_t start__      = std::clock();
        int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
        int d[]                   = {1,2,4,8,16};
        int expected__            = 9;
        std::clock_t start__      = std::clock();
        int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 4: {
        int d[]                   = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3};
        int expected__            = 37;
        std::clock_t start__      = std::clock();
        int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    // custom cases
    /*      case 5: {
    			int d[]                   = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 6: {
    			int d[]                   = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 7: {
    			int d[]                   = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
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
