// Paste me into the FileEdit configuration dialog

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Target {
public:
    vector <string> draw( int n ) {
        char hs = '#';
        char sp = ' ';
        string fr(n, hs);
        string sr(n, sp);
        vector<string> res;
        sr[0] = hs;
        sr[n - 1] = hs;
        int reps = (n - 1) / 2;
        for(int i = 0; i < reps; i++) {
            if(i % 2 == 0) { //fr
                res.push_back(fr);
                for(int j = 1, pos = 1; j <= (i / 2); j++, pos += 2) {
                    res[i][pos] = sp;
                    res[i][n - 1 - pos] = sp;
                }
                cout << i << " : " << res[i] << "\n";
            } else {
                res.push_back(sr);
                for(int j = 1, pos = 2; j <= i / 2; j++, pos+=2) {
                    res[i][pos] = hs;
                    res[i][n - 1 - pos] = hs;
                }
            }
        }
        //now add the first row
        res.push_back(fr);
        int mid = (n + 1) / 2;
        for(int j = 1; j <= n; j+=2) {
            res[mid - 1][j] = sp;
        }

        vector<string> sh;
        for(int i = mid - 2; i >=0; i--) {
            sh.push_back(res[i]);
        }
        res.insert(res.end(), sh.begin(), sh.end());
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

template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) {
    os << "{";
    for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) {
        if (vi != v.begin()) os << ",";
        os << " " << *vi;
    }
    os << " }";
    return os;
}
template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) {
    os << "{";
    for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) {
        if (vi != v.begin()) os << ",";
        os << " \"" << *vi << "\"";
    }
    os << " }";
    return os;
}

int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) {
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
        int n                     = 49;
        string expected__[]       = {"#####", "#   #", "# # #", "#   #", "#####" };

        std::clock_t start__      = std::clock();
        vector <string> received__ = Target().draw(n);
        return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
    }
    case 1: {
        int n                     = 9;
        string expected__[]       = {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" };

        std::clock_t start__      = std::clock();
        vector <string> received__ = Target().draw(n);
        return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
    }
    case 2: {
        int n                     = 13;
        string expected__[]       = {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" };

        std::clock_t start__      = std::clock();
        vector <string> received__ = Target().draw(n);
        return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
    }
    case 3: {
        int n                     = 17;
        string expected__[]       = {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" };

        std::clock_t start__      = std::clock();
        vector <string> received__ = Target().draw(n);
        return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
    }

    // custom cases

    /*      case 4: {
    			int n                     = ;
    			string expected__[]       = ;

    			std::clock_t start__      = std::clock();
    			vector <string> received__ = Target().draw(n);
    			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
    		}*/
    /*      case 5: {
    			int n                     = ;
    			string expected__[]       = ;

    			std::clock_t start__      = std::clock();
    			vector <string> received__ = Target().draw(n);
    			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
    		}*/
    /*      case 6: {
    			int n                     = ;
    			string expected__[]       = ;

    			std::clock_t start__      = std::clock();
    			vector <string> received__ = Target().draw(n);
    			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
