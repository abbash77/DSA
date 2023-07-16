class Solution {
public:
    int recur(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(i<0||j<0||i>=n||j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=-1e9;
        if(i+1<n&&matrix[i+1][j]>matrix[i][j]){
            mini=max(mini,1+recur(i+1,j,n,m,matrix,dp));
        }
        if(j+1<m&&matrix[i][j+1]>matrix[i][j]){
            mini=max(mini,1+recur(i,j+1,n,m,matrix,dp));
        }
        if(i-1>=0&&matrix[i-1][j]>matrix[i][j]){
            mini=max(mini,1+recur(i-1,j,n,m,matrix,dp));
        }
        if(j-1>=0&&matrix[i][j-1]>matrix[i][j]){
            mini=max(mini,1+recur(i,j-1,n,m,matrix,dp));
        }
        if(mini==-1e9){
            return dp[i][j]= 0;
        }
        return dp[i][j]= mini;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=-1e9;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=-1){
                    mini=max(mini,dp[i][j]);
                }
                else{
                    mini=max(mini,recur(i,j,n,m,matrix,dp));
                }
                
            }
        }
        return mini+1;
    }
};