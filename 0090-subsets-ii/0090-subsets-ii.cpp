class Solution {
public:
     void solve(vector<int> &nums,int index,vector<int> &output,vector<vector<int>>& ans){
                ans.push_back(output);
            for(int i=index;i<nums.size();i++){
                if(i>index&&nums[i]==nums[i-1]){
                    continue;
                }
                output.push_back(nums[i]);
                solve(nums,i+1,output,ans);
                output.pop_back();
            }
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(),nums.end());
        solve(nums,0,output,ans);
        return ans;
    }
};