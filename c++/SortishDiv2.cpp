// Paste me into the FileEdit configuration dialog
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class SortishDiv2 {

    int getinv(vector< int > a) {
        int res = 0;
        for(int i = 0, l = a.size(); i < l; i++) {
            for(int j = i + 1; j < l; j++) {
                if(a[i] < a[j]) {
                    res++;
                }
            }
        }
        return res;
    }
public:
    int ways( int sortedness, vector <int> seq ) {
        vector< bool > present(101, false);
        vector< int > there;
        vector< int > missingind;
        for(int i = 0, l = seq.size(); i < l; i++) {
            if(seq[i] == 0) {
                missingind.push_back(i);
            } else {
                there.push_back(seq[i]);
                present[seq[i]] = true;
            }
        }
        vector< int > rem;
        int res = 0;
        int remaining = sortedness - getinv(there);
        if(remaining == 0) {
            if(seq.size() == there.size()) {
                return 1;
            }
        }
        for(int i = 0; i < seq.size(); i++) {
            if(!present[i + 1]) {
                rem.push_back(i + 1);
            }
        }
        sort(rem.begin(), rem.end());
        do {
            for(int i = 0; i < missingind.size(); i++) {
                seq[missingind[i]] = rem[i];
            }
            for(int i = 0; i < seq.size(); i++) {
                cout << seq[i] << " ";
            }
            cout << "\t" << getinv(seq) << "\n";
            if(getinv(seq) == sortedness) {
                res++;
            }
        } while(next_permutation(rem.begin(), rem.end()));

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
        int sortedness            = 5;
        int seq[]                 = {4, 0, 0, 2, 0};
        int expected__            = 2;
        std::clock_t start__      = std::clock();
        int received__            = SortishDiv2().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
        int sortedness            = 4;
        int seq[]                 = {0, 0, 0, 0};
        int expected__            = 5;
        std::clock_t start__      = std::clock();
        int received__            = SortishDiv2().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
        int sortedness            = 2;
        int seq[]                 = {1, 3, 2};
        int expected__            = 1;
        std::clock_t start__      = std::clock();
        int received__            = SortishDiv2().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
        int sortedness            = 2;
        int seq[]                 = {1, 2, 0, 5, 0, 0};
        int expected__            = 0;
        std::clock_t start__      = std::clock();
        int received__            = SortishDiv2().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    // custom cases
    /*      case 4: {
    			int sortedness            = ;
    			int seq[]                 = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = SortishDiv2().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 5: {
    			int sortedness            = ;
    			int seq[]                 = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = SortishDiv2().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 6: {
    			int sortedness            = ;
    			int seq[]                 = ;
    			int expected__            = ;
    			std::clock_t start__      = std::clock();
    			int received__            = SortishDiv2().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
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
