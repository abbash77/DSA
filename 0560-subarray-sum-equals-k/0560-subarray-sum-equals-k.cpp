class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int>m;
        int preSum=0;
        for(int i=0;i<nums.size();i++)
        {
           preSum+=nums[i];
            if(preSum==k)cnt++;
            if(m.find(preSum-k)!=m.end()){
                cnt+=m[preSum-k];
            }
            m[preSum]++;
        }
        return cnt;
    }
};