class Solution {
public:
    int recur(int i,vector<int> &nums,int target,vector<int> &dp){
        if(i>=nums.size()){
            return -1e9;
        }
        if(i==nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi=INT_MIN;
        for(int j=i+1;j<nums.size();j++){
            if(abs(nums[j]-nums[i])<=target){
                maxi=max(maxi,1+recur(j,nums,target,dp)); 
            }
        }
        return dp[i]= maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        int ans=recur(0,nums,target,dp);
        
        if(ans<=-1e9){
            return -1;
        }
        return ans;
    }
};