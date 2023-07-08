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
        int ans=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    int a=1+dp[j];
                    dp[i]=max(a,dp[i]);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};