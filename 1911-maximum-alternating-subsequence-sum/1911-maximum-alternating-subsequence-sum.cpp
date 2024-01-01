class Solution {
public:
    
    long long recur(int i,vector<int> &nums,int even,vector<vector<long long>> &dp){
        if(nums.size()==i){
            
            return 0;
        }
        if(dp[i][even]!=-1){
            return dp[i][even];
        }
        long long notTake=recur(i+1,nums,even,dp);
        long long take=0;
        if(even==0){
            take=nums[i]+recur(i+1,nums,1,dp);
        }
        else{
            take=-nums[i]+recur(i+1,nums,0,dp);
        }
        return dp[i][even]= max(notTake,take);
        
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return recur(0,nums,0,dp);
    }
};