class Solution {
public:
   int func(int i,vector<int>&nums,vector<int> &dp){
       if(i==nums.size()-1){
           return 1;
       }
       if(i>=nums.size()){
           return 0;
       }
       if(dp[i]!=-1){
           return dp[i];
       }
       
       for(int j=1;j<=nums[i];j++){
          if(func(i+j,nums,dp)){
              return dp[i]=1;
          }
       }
       return dp[i]=0;
   }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
       int a= func(0,nums,dp);
        return a;
    }
};