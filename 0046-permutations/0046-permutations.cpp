class Solution {
public:
    void helper(vector<int>& nums,vector<int>& help,vector<vector<int>> &ans,unordered_map<int,bool>& m){
        if(help.size()==nums.size()){
            ans.push_back(help);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!m[nums[i]]){
                help.push_back(nums[i]);
                m[nums[i]]=true;
                helper(nums,help,ans,m);
                help.pop_back();
                m[nums[i]]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> help;
        unordered_map<int,bool> m;
        helper(nums,help,ans,m);
        return ans;
    }
};