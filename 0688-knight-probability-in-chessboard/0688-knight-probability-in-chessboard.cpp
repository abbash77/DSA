class Solution {
public:
    
    double recur(int n, int k, int row, int column, vector<vector<vector<double>>> &dp){
        if(row<0 || column<0 || row>=n || column>=n)return 0;
        if(k==0)return 1;
        if(dp[row][column][k]!=-1){
            return dp[row][column][k];
        }
        double a=recur(n,k-1,row+2,column+1,dp);
        double b=recur(n,k-1,row+1,column+2,dp);
        double c=recur(n,k-1,row-1,column+2,dp);
        double d=recur(n,k-1,row-2,column+1,dp);
        double e=recur(n,k-1,row+2,column-1,dp);
        double f=recur(n,k-1,row+1,column-2,dp);
        double g=recur(n,k-1,row-1,column-2,dp);
        double h=recur(n,k-1,row-2,column-1,dp);
        return dp[row][column][k]= (a+b+c+d+e+f+g+h)/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        double a=recur(n,k,row,column,dp);
       
        
        return a;
    }
};