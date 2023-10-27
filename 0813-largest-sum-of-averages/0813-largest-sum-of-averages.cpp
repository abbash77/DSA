class Solution {
public:
    double recur(int idx,int k,vector<int> nums,vector<vector<double>> &dp){
        if(idx==nums.size()){
            return 0;
        }
        if(!k){
            return INT_MIN;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        double sum=0;
        double maxi=INT_MIN;
        for(int i=idx;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(sum/(i-idx+1)+recur(i+1,k-1,nums,dp),maxi);
        }
        return dp[idx][k]= maxi;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(nums.size(),vector<double>(k+1,-1));
        return recur(0,k,nums,dp);
    }
};