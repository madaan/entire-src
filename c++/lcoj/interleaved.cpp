class Solution {
public:
    string s1, s2, s3;
    int l1, l2, l3;
    int dp[1000][1000];
    int check(int i, int j) {
        int res = 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i == l1 && j == l2) {
            return dp[i][j] = 1;
        }
        int k = i + j;
        if(s1[i] == s3[k]) {
            res = check(i + 1, j);
        }
        if(s2[j] == s3[k]) {
            res = res | check(i, j + 1);
        }
        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        this->l1 = s1.length();
        this->l2 = s2.length();
        this->l3 = s3.length();
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        
        if((l1 + l2) != l3) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return check(0, 0) == 1 ? true : false;
    
    }
};
