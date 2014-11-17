// Paste me into the FileEdit configuration dialog
#include <string>
#include <vector>
#include<bits/stdc++.h>
typedef long long ll;
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())
using namespace std;
class CatsOnTheLineDiv2 {
public:
    string getAnswer( vector <int> position, vector <int> count, int time ) {
        vector<pair<int, int>> cpos;
        for(int i = 0; i < position.size(); i++) {
            cpos.push_back(pair(position[i], count[i]));
        }
        sort(cpos.begin(), cpos.end());
        for(int i = 0; i < cpos.size(); i++) {
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
int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) {
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
        std::cerr << "    Expected: \"" << expected << "\"" << std::endl;
        std::cerr << "    Received: \"" << received << "\"" << std::endl;
    }
    return verdict == "PASSED";
}
int run_test_case(int casenum__) {
    switch (casenum__) {
    case 0: {
        int position[]            = {0};
        int count[]               = {7};
        int time                  = 3;
        string expected__         = "Possible";
        std::clock_t start__      = std::clock();
        string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
        int position[]            = {0};
        int count[]               = {8};
        int time                  = 2;
        string expected__         = "Impossible";
        std::clock_t start__      = std::clock();
        string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
        int position[]            = {0, 1};
        int count[]               = {3, 1};
        int time                  = 0;
        string expected__         = "Impossible";
        std::clock_t start__      = std::clock();
        string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
        int position[]            = {5, 0, 2};
        int count[]               = {2, 3, 5};
        int time                  = 2;
        string expected__         = "Impossible";
        std::clock_t start__      = std::clock();
        string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 4: {
        int position[]            = {5, 1, -10, 7, 12, 2, 10, 20};
        int count[]               = {3, 4, 2, 7, 1, 4, 3, 4};
        int time                  = 6;
        string expected__         = "Possible";
        std::clock_t start__      = std::clock();
        string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
        return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    // custom cases
    /*      case 5: {
    			int position[]            = ;
    			int count[]               = ;
    			int time                  = ;
    			string expected__         = ;
    			std::clock_t start__      = std::clock();
    			string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 6: {
    			int position[]            = ;
    			int count[]               = ;
    			int time                  = ;
    			string expected__         = ;
    			std::clock_t start__      = std::clock();
    			string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
    			return verify_case(casenum__, expected__, received__, clock()-start__);
    		}*/
    /*      case 7: {
    			int position[]            = ;
    			int count[]               = ;
    			int time                  = ;
    			string expected__         = ;
    			std::clock_t start__      = std::clock();
    			string received__         = CatsOnTheLineDiv2().getAnswer(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
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
