class Solution {
public:
    int recur(int i,int j,vector<int> nums,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=-1e9;
        for(int k=i;k<=j;k++){
            int val=nums[i-1]*nums[k]*nums[j+1]+recur(i,k-1,nums,dp)+recur(k+1,j,nums,dp);
            maxi=max(maxi,val);
        }
        return dp[i][j]= maxi;
    }
    int maxCoins(vector<int>& nums) {
        int c=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
                int maxi=-1e9;
                for(int k=i;k<=j;k++){
                    int val=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,val);
                }
                dp[i][j]= maxi;
            }
        }
        return dp[1][c];
    }
};