class Solution {
public:
    int MOD=1e9+7;
    int recur(int m,int n, int k, int row, int column, vector<vector<vector<double>>> &dp){
        if(row<0 || column<0 || row>=m || column>=n)return 1;
        if(k==0)return 0;
        if(dp[row][column][k]!=-1){
            return dp[row][column][k];
        }
        int ans=0;
        ans=ans%MOD+recur(m,n,k-1,row,column+1,dp)%MOD;
        ans=ans%MOD+recur(m,n,k-1,row+1,column,dp)%MOD;
        ans=ans%MOD+recur(m,n,k-1,row-1,column,dp)%MOD;
        ans=ans%MOD+recur(m,n,k-1,row,column-1,dp)%MOD;
       
        return dp[row][column][k]= (ans);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<double>>> dp(m+1,vector<vector<double>>(n+1,vector<double>(maxMove+1,-1)));
        return recur(m,n,maxMove,startRow,startColumn,dp)%MOD;
    }
};