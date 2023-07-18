class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<long long> prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(prefix[i]-(sum-prefix[i])>=0){
                ans++;
            }
        }
        return ans;
    }
};