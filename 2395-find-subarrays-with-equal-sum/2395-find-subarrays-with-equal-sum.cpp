class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,bool> m;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            if(m.find(sum)!=m.end()){
                return true;
            }
            m[sum]=true;
            sum-=nums[i-1];
        }
        return false;
    }
};