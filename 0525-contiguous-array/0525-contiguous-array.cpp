class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int pre = 0, res = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) nums[i] = -1;
        }
        for(int i = 0; i < n; i++){
            pre += nums[i];
            if(pre == 0) res = i+1;
            if(mp.find(pre) == mp.end()) mp.insert({pre, i});	
            else res = max(res, i-mp[pre]);
        }
        return res;
    }
};