class Solution {
public:
    int recur(int i,vector<int> nums,vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int a=recur(i+2,nums,dp);
        int b=recur(i+3,nums,dp);
        return dp[i]=nums[i]+max(a,b);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int i=0;
        int a=recur(i,nums,dp);
        int b=recur(i+1,nums,dp);
        return max(a,b);
    }
};