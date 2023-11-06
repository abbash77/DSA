class Solution {
public:
    int recur(int i,vector<int>& nums,vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int notTake=recur(i+1,nums,dp);
        int sum=nums[i];
        int val=nums[i];
        int idx=i+1;
        while(idx<nums.size()&&nums[idx]==val){
            sum+=nums[i];
            idx++;
        }
        while(idx<nums.size()&&nums[idx]-val==1){
            idx++;
        }
        int take=sum+recur(idx,nums,dp);
        
        
        
        return dp[i]= max(take,notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,-1);
        return recur(0,nums,dp);
    }
};