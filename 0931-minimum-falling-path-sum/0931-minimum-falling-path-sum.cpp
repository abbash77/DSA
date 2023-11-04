class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX, n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        dp[0] = matrix[0];
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int l = 1e9, a = 1e9, r = 1e9;
                if(j > 0) l = dp[i - 1][j - 1];
                a = dp[i - 1][j];
                if(j + 1 < n) r = dp[i - 1][j + 1];
                dp[i][j] = matrix[i][j] + min(l, min(a, r));
            }
        }

        for(int i=0; i<n; i++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
   
};