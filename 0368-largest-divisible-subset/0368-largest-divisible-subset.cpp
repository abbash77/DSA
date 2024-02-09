class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        sort(nums.begin(),nums.end());
        int lastIndex=-1;
        int maxi=INT_MIN;
        vector<int> ans;
        if(nums.size()==1){
            return nums;
        }
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&1+dp[j]>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                
                lastIndex=i;
            }
        }
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        return ans;
        
    }
};