//sg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tl, sl;
    string S, T;
    vector< vector < int > > dp;
    int ans(int i, int j) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(j == tl) {
            return dp[i][j] = 1;
        }
        if(i == sl) {
            return dp[i][j] = 0;
        }
        if(S[i] == T[j]) {
            dp[i + 1][j] = ans(i + 1, j);
            dp[i + 1][j + 1] =  ans(i + 1, j + 1);
            return dp[i + 1][j] + dp[i + 1][j + 1];
        } else {
            dp[i + 1][j] =  ans(i + 1, j);
            return dp[i + 1][j];
        }
    }
    int numDistinct(string S, string T) {
        sl = S.length();
        tl = T.length();
        dp = vector< vector < int > > (sl + 1, vector< int > (tl + 1, -1));
        this->S = S;
        this->T = T;
        return ans(0, 0);
    }
};
int main() {
    Solution s;
    string a("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo");
    string b("rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys");
    //cout << a.length() << "\n";
    cout << s.numDistinct(string(""), string("a")) << "\n";
    cout << s.numDistinct(a, b) << "\n";
    return 0;
}
