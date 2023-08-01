class Solution {
public:
    
    int minimumDeleteSum(string s1, string s2) {
        const int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

        // base case
        dp[len1][len2] = 0;
        for (int i1 = len1 - 1; i1 >= 0; i1--) dp[i1][len2] = dp[i1 + 1][len2] + s1[i1];
        for (int i2 = len2 - 1; i2 >= 0; i2--) dp[len1][i2] = dp[len1][i2 + 1] + s2[i2];

        // dynamic programming
        for (int i1 = len1 -1; i1 >= 0; i1--) {
            for (int i2 = len2 - 1; i2 >= 0; i2--) {
                if (s1[i1] == s2[i2]) dp[i1][i2] = dp[i1 + 1][i2 + 1];
                else dp[i1][i2] = min(s1[i1] + dp[i1 + 1][i2], s2[i2] + dp[i1][i2 + 1]);
            }
        }

        return dp[0][0];
    }
};