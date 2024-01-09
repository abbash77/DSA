class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_map<int,int> m;
        long long ans=0;
        long long sum=0;
        while(j<nums.size()){
            if(j-i+1<k){
                sum+=nums[j];
                m[nums[j]]++;
                j++;
            }
            else{
                sum+=nums[j];
                m[nums[j]]++;
                if(m.size()==j-i+1){
                    ans=max(ans,sum);
                    
                }
                sum-=nums[i];
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};