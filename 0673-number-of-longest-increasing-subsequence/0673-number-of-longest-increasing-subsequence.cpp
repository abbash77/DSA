class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi=1;
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1==dp[i]){
                        cnt[i]+=cnt[j];
                        ans=max(ans,cnt[i]);
                    }
                    else if(dp[j]+1>dp[i]){
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
            
        }
        int nos=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                nos+=cnt[i];
            }
        }
        return nos;
    }
};