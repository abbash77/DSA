class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int solve(int n, int cell, vector<vector<int>> &dp){
        if(n == 0)  return 1;
        if(dp[cell][n] != -1)   return dp[cell][n];
        int ans = 0;
        for(int nextCell: adj[cell]){
            ans = (ans + solve(n-1, nextCell, dp)) % M;
        }
        return dp[cell][n] = ans;
    }
    int knightDialer(int n) {
        int result = 0;
        vector<vector<int>> dp(10, vector<int> (n+1, -1));
        for(int cell=0; cell<=9; cell++){
            result = (result + solve(n-1, cell, dp) % M)%M;
        }
        return result;
    }
};