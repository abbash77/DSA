class Solution {
public:
    int recur(int i,int prevcol,vector<vector<int>>& grid,int n,vector<vector<int>> &dp){
        if(i==n-1){
            int ret=INT_MAX;
            for(int j=0;j<n;j++){
                if(j!=prevcol){
                    ret=min(ret,grid[i][j]);
                }
            }
            return ret;
        }
        if(dp[i][prevcol]!=-1){
            return dp[i][prevcol];
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            if(j!=prevcol){
                ans=min(ans,grid[i][j]+recur(i+1,j,grid,n,dp));
            }
        }
        return dp[i][prevcol]= ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(204,-1));
        return recur(0,202,grid,n,dp);
    }
};