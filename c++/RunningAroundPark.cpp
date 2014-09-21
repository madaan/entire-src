// Paste me into the FileEdit configuration dialog

#include <string>
#include <vector>
using namespace std;

class RunningAroundPark {
public:
   int numberOfLap( int N, vector <int> d ) {
       int l  = d.size();
       if(l == 1) {
           return 1;
       }
       if(l == 2) {
           if(d[0] < d[1]) {
               return 1;
           } else {
               return 2;
            }
       }
       int res = 1;
       for(int i = 1; i < l; i++) {
           if(d[i - 1] >= d[i]) {
               res++;
           }
       }
       if(res == 0) {
           return 1;
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
			int N                     = 3;
			int d[]                   = {1,2,3};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = RunningAroundPark().numberOfLap(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 24;
			int d[]                   = {6,6};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = RunningAroundPark().numberOfLap(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int d[]                   = {3,2,1};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = RunningAroundPark().numberOfLap(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 50;
			int d[]                   = {1,3,5,7,9,2,4,6,8,10};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = RunningAroundPark().numberOfLap(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RunningAroundPark().numberOfLap(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RunningAroundPark().numberOfLap(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RunningAroundPark().numberOfLap(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
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
