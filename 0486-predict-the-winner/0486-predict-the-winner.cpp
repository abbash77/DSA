class Solution {
public:
    
  
     int recur(int i,int j,int a,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
         int x=0;
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
        if(a){
            x=max(nums[i]+recur(i+1,j,0,nums,dp),nums[j]+recur(i,j-1,0,nums,dp));
        }
         else{
             x=min(-nums[i]+recur(i+1,j,1,nums,dp),-nums[j]+recur(i,j-1,1,nums,dp));
         }
         return dp[i][j]= x;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recur(0,n-1,1,nums,dp)>=0;
    }
};