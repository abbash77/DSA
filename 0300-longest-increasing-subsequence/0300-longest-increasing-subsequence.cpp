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
        vector<int> after(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int notTake=after[j+1];
                int take=0;
                if(j==-1||nums[j]<nums[i]){
                    take=1+after[i+1];

                }
                curr[j+1]= max(notTake,take);
            }
            after=curr;
        }
        return curr[-1+1];
    }
};