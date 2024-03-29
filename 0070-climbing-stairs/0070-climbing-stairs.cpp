class Solution {
public:
    int recur(int n,int i,vector<int> &dp){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=recur(n,i+1,dp)+recur(n,i+2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return recur(n,0,dp);
    }
};