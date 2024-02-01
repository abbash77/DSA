class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i=i+3){
            if(abs(nums[i]-nums[i+2])<=k){
                vector<int> v{nums[i],nums[i+1],nums[i+2]};
                ans.push_back(v);
            }
            else{
                ans.clear();
                return ans;
            }
        }
        return ans;
        
    }
};