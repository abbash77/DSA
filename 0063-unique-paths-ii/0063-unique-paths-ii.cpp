class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp, int& m, int& n,vector<vector<int>>& obstacleGrid) {
        if(i == m-1 && j == n-1&&obstacleGrid[i][j]==0) return 1;
        if(i>=m||j>=n){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        
        dp[i][j] = solve(i+1, j, dp, m, n,obstacleGrid) + solve(i, j+1, dp, m, n,obstacleGrid);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(0, 0, dp, m, n,obstacleGrid);
    }
};