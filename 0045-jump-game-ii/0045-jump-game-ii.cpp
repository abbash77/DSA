class Solution {
public:
    vector<int> dp;
    int recur(int i,int n,vector<int>& nums){
        if(i==n-1){
            return 0;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini=1e9;
        for(int j=1;j<=nums[i];j++){
            mini=min(1+recur(i+j,n,nums),mini);
        }
        return dp[i]= mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return recur(0,n,nums);
    }
};