class Solution {
public:
    void recur(int idx,vector<int> &nums,set<vector<int>> &ans){
        if(idx>=nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            recur(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> finalAns;
        set<vector<int>> ans;
        
        recur(0,nums,ans);
        for(auto val:ans){
            finalAns.push_back(val);
        }
        return finalAns;
    }
};