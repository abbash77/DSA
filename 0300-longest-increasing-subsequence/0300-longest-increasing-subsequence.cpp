class Solution {
public:
    int recur(int i,int prev,vector<int>& nums,vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int notTake=recur(i+1,prev,nums,dp);
        int take=0;
        if(prev==-1||nums[prev]<nums[i]){
            take=1+recur(i+1,i,nums,dp);
            
        }
        return dp[i][prev+1]= max(notTake,take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int notTake=dp[i+1][j+1];
                int take=0;
                if(j==-1||nums[j]<nums[i]){
                    take=1+dp[i+1][i+1];

                }
                dp[i][j+1]= max(notTake,take);
            }
        }
        return dp[0][-1+1];
    }
};