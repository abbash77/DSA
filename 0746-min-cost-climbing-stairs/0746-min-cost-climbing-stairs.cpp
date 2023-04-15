class Solution {
public:
    int recur(int n,vector<int>& cost,vector<int>& dp){
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int left=recur(n-1,cost,dp)+cost[n];
        int right=recur(n-2,cost,dp)+cost[n];
        return dp[n]=min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        int a=recur(n-1,cost,dp);
        int b=recur(n-2,cost,dp);
        return min(a,b);
    }
};