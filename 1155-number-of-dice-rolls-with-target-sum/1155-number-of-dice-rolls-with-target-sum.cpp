class Solution {
public:
    int MOD=1e9+7;
    int recur(int i,int n,int k,int target,vector<vector<int>> &dp){
        if(target==0&&i==n){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        
        int ans=0;
        for(int j=1;j<=k;j++){
            ans=(ans+recur(i+1,n,k,target-j,dp))%MOD;
            
        }
        return dp[i][target] =ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return recur(0,n,k,target,dp)%MOD;
    }
};